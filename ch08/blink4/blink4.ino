#include <Adafruit_NeoPixel.h>

#define STICK_PIN   2
#define STICK_COUNT 8
#define RING_PIN    4
#define RING_COUNT 24

// Declare our NeoPixel strip object per documentation from Adafruit
// https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use

Adafruit_NeoPixel stick(STICK_COUNT, STICK_PIN);
Adafruit_NeoPixel ring(RING_COUNT, RING_PIN, NEO_GRBW);

void setup() {
  stick.begin();            // Initialize our stick
  stick.setBrightness(128); // Set a comfortable mid-level brightness
  stick.show();             // Start with all pixels off
  ring.begin();             // Initialize our ring
  ring.setBrightness(128);  // Set a comfortable mid-level brightness
  ring.show();              // Start with all pixels off
}

void loop() {
  // our stick and ring have different LED counts, so we have to be a little
  // clever with our loop. There are several ways to do this. We'll use
  // modulus math, but can you think of other solutions that would achieve
  // the same pattern?
  for (int p = 0; p < RING_COUNT; p++) {
    stick.clear();
    stick.setPixelColor(p % STICK_COUNT, 0, 0, 255);
    ring.clear();
    ring.setPixelColor(p, 0, 255, 0, 0);
    
    stick.show();
    ring.show();
    delay(1000);
  }
}
