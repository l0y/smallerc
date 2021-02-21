#define D2 2

void setup() {
  // put your setup code here, to run once:
  // Tell our board we want to write to digital pin 2
  pinMode(D2, OUTPUT);
}

void loop() {
  digitalWrite(D2, HIGH);
  delay(2000);
  digitalWrite(D2, LOW);
  delay(1000);
}
