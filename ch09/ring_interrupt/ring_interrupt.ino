#include <Adafruit_NeoPixel.h>

#define RING_PIN    3
#define RING_COUNT 24
#define BUTTON_PIN  2

int pause = 1000;

// Declare our NeoPixel strip object per documentation from Adafruit
// https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use

Adafruit_NeoPixel ring(RING_COUNT, RING_PIN, NEO_GRBW);

void nextPause() {
  if (pause == 250) {
    pause = 1000;
  } else {
    pause /= 2;
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), nextPause, FALLING);
  ring.begin();             // Initialize our ring
  ring.setBrightness(128);  // Set a comfortable mid-level brightness
  ring.show();              // Start with all pixels off
}

void loop() {
  for (int p = 0; p < RING_COUNT; p++) {
    ring.clear();
    ring.setPixelColor(p, 0, 255, 0, 0);    
    ring.show();
    delay(pause);
  }
}
