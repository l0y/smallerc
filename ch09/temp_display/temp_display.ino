// TMP36 is a 10-bit (0 - 1023) analog sensor
// 10mV / C with 500mV offset for temps below 0
// Our 4-digit display uses a TM1637 chip and I2C
#include <TM1637Display.h>

// Name our pins
#define TMP36_PIN 0
#define CLK       2
#define DIO       3
#define BUTTON    8

// Create our 4-segment display object
TM1637Display display(CLK, DIO);

// Build the letters "F" and "C"
// Segment bits run clockwise from top (bit 1) to center (64)
uint8_t segmentF[] = { 1 | 32 | 64 | 16 };
uint8_t segmentC[] = { 1 | 32 | 16 | 8 };

// Keep track of scale
bool useC = false;

// Manage button at human time
bool debounce = false;

void setup() {
  Serial.begin(115200);
  display.clear();
  display.setBrightness(0x0f);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int raw = analogRead(TMP36_PIN);
  float asVolts = raw * 5.0 / 1024;  // Connected to 5V
  float asC = (asVolts - 0.5) * 100;
  int wholeC = (int)(asC + 0.5);
  int wholeF = (int)((asC * 1.8) + 32 + 0.5);
  Serial.print(raw);
  Serial.print(" ");
  Serial.println(asC);
  if (useC) {
    display.showNumberDec(wholeC, false, 3, 0);
    display.setSegments(segmentC, 1, 3);
  } else {
    display.showNumberDec(wholeF, false, 3, 0);
    display.setSegments(segmentF, 1, 3);
  }
  if (debounce) {
    debounce = false;
    delay(1000);
  } else {
    for (int i =0; i < 1000; i += 10) {
      int toggle = digitalRead(BUTTON);
      if (toggle == LOW) {
        useC = !useC;
        debounce = true;
        break;
      }
      delay(10);
    }
  }
}
