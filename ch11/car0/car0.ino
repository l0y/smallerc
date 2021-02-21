/*
 * An initial, no frills car driving project with basic, on/off
 * motor control (i.e. no speed variation) and joystick navigation
 */
#define LEFT_BTN  12
#define RIGHT_BTN  9
#define FWD_BTN   10
#define BKWD_BTN  11

#define AIN1 4
#define AIN2 5
#define BIN1 6
#define BIN2 7

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
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void forward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void backward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void left() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void right() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void loop() {
  byte fbtn = digitalRead(FWD_BTN);
  byte bbtn = digitalRead(BKWD_BTN);
  byte lbtn = digitalRead(LEFT_BTN);
  byte rbtn = digitalRead(RIGHT_BTN);

  // We only support one direction at a time, so an
  // if/else chain is perfect
  if (fbtn == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    forward();
  } else if (bbtn == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    backward();
  } else if (lbtn == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    left();
  } else if (rbtn == LOW) {
    digitalWrite(LED_BUILTIN, HIGH);
    right();
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    allstop();
  }
}
