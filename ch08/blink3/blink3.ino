#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN   4
#define PIXEL_COUNT 1

// Declare our NeoPixel strip object per documentation from Adafruit
// https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN);

void setup() {
  strip.begin();            // Our library helps get things ready
  strip.setBrightness(128); // Set a comfortable mid-level brightness
  strip.show();             // Start with all pixels off
}

void loop() {
  // Show red for 1 second
  strip.setPixelColor(0, 255, 0, 0);
  strip.show();
  delay(1000);
  // Show green for 1 second
  strip.setPixelColor(0, 0, 255, 0);
  strip.show();
  delay(1000);
  // Show blue for 1 second
  strip.setPixelColor(0, 0, 0, 255);
  strip.show();
  delay(1000);
}
