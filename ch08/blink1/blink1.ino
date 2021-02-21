void setup() {
  // put your setup code here, to run once:
  // Tell our board we want to write to the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // A high value is 'on' for an LED
  digitalWrite(LED_BUILTIN, HIGH);
  // Now wait for 500 milliseconds
  delay(500);
  // And write a low value to turn our LED off
  digitalWrite(LED_BUILTIN, LOW);
  // and wait another 500ms
  delay(500);
}
