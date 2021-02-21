// Our 4-digit display uses a TM1637 chip and I2C
#include <TM1637Display.h>

// Name our pins
#define CLK       2
#define DIO       3

// Create our 4-segment display object
TM1637Display display(CLK, DIO);

void setup() {
  // Get our display ready and set a medium brightness
  display.clear();
  display.setBrightness(0x0f);
  display.showNumberDec(1234);
}

void loop() {
}
