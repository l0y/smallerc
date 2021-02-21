/*
 * Final version of our remote control car project. This version
 * pairs with the "controller" project. We have removed the joystick
 * and instead, poll the radio to see if it picked up any transmitted
 * directions which we then use to select a drive function.
 */

#include "pins.h"
#include "SmalleRC.h"

void setup() {
  Serial.begin(115200);
  // Send output to the motor pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  if (rc_start() != rc_INIT_SUCCESS) {
    Serial.println("Failed to initialize radio.");
  }
}

void loop() {
  direction_t dir = rc_receive();
  if (dir > 0) { // Driving!
    switch (dir) {
      case rc_FORWARD:
        forward();
        break;
      case rc_BACKWARD:
        backward();
        break;
      case rc_LEFT:
        left();
        break;
      case rc_RIGHT:
        right();
        break;
    }
    delay(20);
  } else {
    // Stopping, or eventually we could handle errors, too
    allstop();
  }
}
