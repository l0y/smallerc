#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Grab credentials from config.h and setup our feed
#include "config.h"
AdafruitIO_Feed *smallerc = io.feed("smallerc");

// Setup our OLED
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # 
#define SCREEN_ADDRESS 0x3C // See datasheet, 128x32 screen
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
char statusline[22] = "Starting...";

// A few things for keeping an average temperature reading
float total = 0.0;
int   count = 0;

void setup() {
  Serial.begin(115200);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show Adafruit splash screen initialized by the display library
  display.display();

  // Now setup the connection to adafruit.io
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());


  // Setup our display for simple (if small) text
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.println(statusline);
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A2);
  float voltage = reading / 1024.0;
  if (count == 0) {
    total = voltage;
  } else {
    total += voltage;
  }
  count++;
  float avg = total / count;
  float tempC = (avg - 0.5) * 100;
  float tempF = tempC * 1.8 + 32;
  if (count % 100 == 0) {
    // Update our display every 10 seconds
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(statusline);
    display.print(reading);
    display.print("  ");
    display.println(voltage);
    display.print(tempC);
    display.println("\370 C");
    display.print(tempF);
    display.println("\370 F");
    display.display();
    strcpy(statusline, "Reading...");
  }
  if (count % 600 == 0) {
    // Update our IoT feed every minute
    smallerc->save(tempF);
    strcpy(statusline, "Feed updated");
  }
  delay(100);
}
