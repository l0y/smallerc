// "breathing" fade on an RGB LED

// Output pins, have to make sure they support PWM
// https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
#define RED    5
#define GREEN  6
#define BLUE   9

// Some helper values
#define RATE 5000
#define PI_2 6.283185

// Color channels for our LED
byte red;
byte green;
byte blue;

void setup() {
  Serial.begin(115200);
  // Set our output pins
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  // Start the LED "off"
  digitalWrite(RED, 0);
  digitalWrite(GREEN, 0);
  digitalWrite(BLUE, 0);
  // Get our PRNG ready then pick our random colors
  randomSeed(analogRead(0));
  // And pick our random color, but make sure it's relatively bright
  red = random(128,255);
  green = random(128,255);
  blue = random(128,255);
  // Print the result as a web color
  Serial.print(red, HEX);
  Serial.print(green, HEX);
  Serial.println(blue, HEX);
  // And show it on the LED for a few seconds before starting the animation
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
  delay(RATE);
}

void loop() {
  double ms_in_radians = (millis() % RATE) * PI_2 / RATE;
  double breath = (sin(ms_in_radians) + 1.0) / 2.0;
  analogWrite(RED, red * breath);
  analogWrite(GREEN, green * breath);
  analogWrite(BLUE, blue * breath);
  delay(10);
}
