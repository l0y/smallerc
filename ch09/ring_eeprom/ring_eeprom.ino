#include <Adafruit_NeoPixel.h>
#include <EEPROM.h>

#define RING_PIN    3
#define RING_COUNT 24
#define BUTTON_PIN  2

int previousState = HIGH;
int pause = 250;
int countdown = -1;

const PROGMEM uint32_t colors[] = {
  0xCC000000, 0x00CC0000, 0x0000CC00, 0x000000CC,
  0xCC336699, 0xCC663399, 0xCC339966, 0xCC996633
};
const byte colorCount = 8;
byte colorIndex;

// Declare our NeoPixel strip object per documentation from Adafruit
// https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use

Adafruit_NeoPixel ring(RING_COUNT, RING_PIN, NEO_GRBW);

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  retrieveIndex();          // grab our color index from EEPROM
  ring.begin();             // Initialize our ring
  ring.setBrightness(128);  // Set a comfortable mid-level brightness
  ring.fill(pgm_read_dword(&colors[colorIndex]));
  ring.show();
}

void loop() {
  int toggle = digitalRead(BUTTON_PIN);
  if (toggle != previousState) {
    if (toggle == LOW) {
      // "falling" state, so do our work
      previousState = LOW;
      colorIndex++;
      if (colorIndex >= colorCount) {
        colorIndex = 0;
      }
      ring.fill(pgm_read_dword(&colors[colorIndex]));
      ring.show();
      countdown = 10;
    } else {
      // "rising", just record the new state
      previousState = HIGH;
    }
  }
  if (countdown > 0) {
    countdown--;
  } else if (countdown == 0) {
    // Time's up! Record the current color index to EEPROM
    countdown = -1; // stop counting down
    storeIndex();
  }
  delay(100);
}

void retrieveIndex() {
  Serial.print(F("RETRIEVE ... "));
  EEPROM.get(0, colorIndex);
  if (colorIndex < 0 || colorIndex >= colorCount) {
    Serial.println(F("ERROR, using default"));
    // Got a bad value from EEPROM, use default of 0
    colorIndex = 0;
    // And try to store this good value
    storeIndex();
  } else {
    Serial.print(colorIndex);
    Serial.println(F(" OK"));
  }
}

void storeIndex() {
  Serial.print(F("STORE ... "));
  Serial.print(colorIndex);
  EEPROM.put(0, colorIndex);
  Serial.println(F(" OK"));
}
