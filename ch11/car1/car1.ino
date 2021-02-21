/*
 * Next step car project, with more abstraction even though we
 * are still using the same basic setup as we do with car0.
 * We'll use a few extra functions here in preparation for
 * creating a library and eventually to support remote radio
 * control.
 */

// Define the pins we're using for the joystick and the motor
#define LEFT_BTN  12
#define RIGHT_BTN  9
#define FWD_BTN   10
#define BKWD_BTN  11

#define AIN1 4
#define AIN2 5
#define BIN1 6
#define BIN2 7

// Define our direction type
typedef char direction_t;

// Define our direction constants
const direction_t STOP     = 0;
const direction_t LEFT     = 1;
const direction_t RIGHT    = 2;
const direction_t FORWARD  = 3;
const direction_t BACKWARD = 4;

// And define the default speed for our motors
#define SPEED 150

void setup() {
  // Tell our board we want to write to the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);

  // Accept input from the joystick pins
  pinMode(LEFT_BTN, INPUT_PULLUP);
  pinMode(RIGHT_BTN, INPUT_PULLUP);
  pinMode(FWD_BTN, INPUT_PULLUP);
  pinMode(BKWD_BTN, INPUT_PULLUP);

  // Send output to the motor pins
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // And make sure our LED is off
  digitalWrite(LED_BUILTIN, LOW);
}

void allstop() {
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 0);
}

void forward(int speed) {
  analogWrite(AIN1, 0);
  analogWrite(AIN2, speed);
  analogWrite(BIN1, speed);
  analogWrite(BIN2, 0);
}

void backward(int speed) {
  analogWrite(AIN1, speed);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, speed);
}

void left(int speed) {
  analogWrite(AIN1, speed);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 0);
}

void right(int speed) {
  analogWrite(AIN1, 0);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, speed);
}

direction_t readDirection() {
  if (digitalRead(FWD_BTN) == LOW) {
    return FORWARD;
  }
  if (digitalRead(BKWD_BTN) == LOW) {
    return BACKWARD;
  }
  if (digitalRead(LEFT_BTN) == LOW) {
    return LEFT;
  }
  if (digitalRead(RIGHT_BTN) == LOW) {
    return RIGHT;
  }
  // No buttons were pressed, so return STOP
  return STOP;
}

void loop() {
  direction_t dir = readDirection();
  if (dir > 0) { // Driving!
    digitalWrite(LED_BUILTIN, HIGH);
    switch (dir) {
      case FORWARD:
        forward(SPEED);
        break;
      case BACKWARD:
        backward(SPEED);
        break;
      case LEFT:
        left(SPEED);
        break;
      case RIGHT:
        right(SPEED);
        break;
    }
  } else {
    // Stopping, or eventually we could handle errors, too
    digitalWrite(LED_BUILTIN, LOW);
    allstop();
  }
}
