#include <Adafruit_NeoPixel.h>

#define LED_PIN     4
#define LED_COUNT   8
#define RATE     5000
#define PI_2 6.283185

Adafruit_NeoPixel stick(LED_COUNT, LED_PIN, NEO_GRB);
uint32_t colors[] = {
  0xFF0000, 0x00FF00, 0x0000FF, 0x3377FF,
  0x00FFFF, 0xFF00FF, 0xFFFF00, 0xFF7733
};

void setup() {
  Serial.begin(115200);
  stick.begin();             // Initialize our LEDs
  stick.setBrightness(80);  // Set a comfortable brightness
  // Show our colors for a few seconds before animating
  for (byte p = 0; p < LED_COUNT; p++) {
    stick.setPixelColor(p, colors[p]);
  }
  stick.show();
  delay(RATE);
}

void loop() {
  double ms_in_radians = (millis() % RATE) * PI_2 / RATE;
  double breath = (sin(ms_in_radians) + 1.0) / 2.0;
  for (byte p = 0; p < LED_COUNT; p++) {
    byte red   = (colors[p] & 0xFF0000) >> 16;
    byte green = (colors[p] & 0x00FF00) >> 8;
    byte blue  = colors[p] & 0x0000FF;
    red = (byte)(red * breath);
    green = (byte)(green * breath);
    blue = (byte)(blue * breath);
    stick.setPixelColor(p, red, green, blue);
  }
  stick.show();
  delay(10);
}
