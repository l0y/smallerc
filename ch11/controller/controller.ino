/*
 * The controller portion of our final remote control car project.
 * This project pairs with the car3 project (and the SmalleRC library).
 * We have separated the joystick and added a radio. We poll the joystick
 * as before, but instead of turning the motor wheels, we now broadcast
 * the selected direction (if any).
 */

#include "SmalleRC.h"

#define LEFT_BTN  9
#define RIGHT_BTN 7
#define FWD_BTN   8
#define BKWD_BTN  6

void setup() {
  Serial.begin(115200);
  // Accept input from the joystick pins
  pinMode(LEFT_BTN, INPUT_PULLUP);
  pinMode(RIGHT_BTN, INPUT_PULLUP);
  pinMode(FWD_BTN, INPUT_PULLUP);
  pinMode(BKWD_BTN, INPUT_PULLUP);

  if (rc_start() != rc_INIT_SUCCESS) {
    Serial.println("Failed to initialize radio.");
  }
}

direction_t readDirection() {
  if (digitalRead(FWD_BTN) == LOW) {
    return rc_FORWARD;
  }
  if (digitalRead(BKWD_BTN) == LOW) {
    return rc_BACKWARD;
  }
  if (digitalRead(LEFT_BTN) == LOW) {
    return rc_LEFT;
  }
  if (digitalRead(RIGHT_BTN) == LOW) {
    return rc_RIGHT;
  }
  // No buttons were pressed, so return STOP
  return rc_STOP;
}

void loop() {
  direction_t dir = readDirection();
  rc_send(dir);
  delay(10);
}
