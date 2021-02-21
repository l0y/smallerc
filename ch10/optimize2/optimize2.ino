#include <Adafruit_NeoPixel.h>

#define LED_PIN     4
#define LED_COUNT   8
#define RATE     5000

Adafruit_NeoPixel stick(LED_COUNT, LED_PIN, NEO_GRB);
byte colors[8][3] = {
  { 0xFF, 0x00, 0x00 }, { 0x00, 0xFF, 0x00 },
  { 0x00, 0x00, 0xFF }, { 0x33, 0x77, 0xFF },
  { 0x00, 0xFF, 0xFF }, { 0xFF, 0x00, 0xFF },
  { 0xFF, 0xFF, 0x00 }, { 0xFF, 0x77, 0x33 }
};

uint8_t breaths[256];

void setup() {
  Serial.begin(115200);
  stick.begin();             // Initialize our LEDs
  stick.setBrightness(80);  // Set a comfortable brightness
  // Show our colors for a few seconds before animating
  for (byte p = 0; p < LED_COUNT; p++) {
    stick.setPixelColor(p, colors[p][0], colors[p][1], colors[p][2]);
  }
  stick.show();
  // Now initialize our sine lookup table
  for (int s = 0; s <= 255; s++) {
    breaths[s] = stick.sine8(s);
  }
  delay(2000);
}

void loop() {
  uint8_t ms = (millis() % RATE) / 20; // close enough! :)
  uint8_t breath = breaths[ms];
  for (byte p = 0; p < LED_COUNT; p++) {
    byte red   = colors[p][0] * breath / 255;
    byte green = colors[p][1] * breath / 255;
    byte blue  = colors[p][2] * breath / 255;
    stick.setPixelColor(p, red, green, blue);
  }
  stick.show();
  delay(10);
}
