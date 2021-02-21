// TMP36 is a 10-bit (0 - 1023) analog sensor
// 10mV / C with 500mV offset for temps below 0
#define TMP36_PIN 0

void setup() {
  Serial.begin(115200);
}

void loop() {
  int raw = analogRead(TMP36_PIN);
  float asVolts = raw * 5.0 / 1024;  // Connected to 5V
  float asC = (asVolts - 0.5) * 100;
  Serial.print(asC);
  Serial.println(" degrees C");
  float asF = (asC * 1.8) + 32;
  Serial.print(asF);
  Serial.println(" degrees F");
  delay(5000);
}
