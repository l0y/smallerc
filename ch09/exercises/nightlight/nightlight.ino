#define NIGHTLIGHT 5
#define PHOTOCELL  0
void setup() {
  // analog reading and writing (PWM) does not require pinMode() setup
}

void loop() {
  int reading = analogRead(PHOTOCELL);
  int lighting = map(reading, 0, 1023, 255, 0);
  analogWrite(NIGHTLIGHT, lighting);
}
