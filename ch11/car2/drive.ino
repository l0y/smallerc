
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
