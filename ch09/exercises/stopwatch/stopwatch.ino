#include <TM1637Display.h>

#define CLK       6
#define DIO       7
#define BUTTON    2

// Create our 4-segment display object
TM1637Display display(CLK, DIO);

long start = 0;
byte mode  = 0;

void startStopReset() {
  if (mode == 0) {
    start = millis();
    mode = 1;
  } else if (mode == 1) {
    mode = 2;
  } else {
    mode = 0;
    display.showNumberDecEx(0,0);
  }
}

void setup() {
  pinMode(BUTTON, INPUT_PULLUP);
  
  display.clear();
  display.setBrightness(0x0f);
  display.showNumberDec(0);

  attachInterrupt(digitalPinToInterrupt(BUTTON), startStopReset, FALLING);
}

void loop() {
  if (mode == 1) {
    long now_ms = millis();
    long elapsed = constrain((now_ms - start) / 10, 1, 9999);
    display.showNumberDecEx(elapsed, 0x40);
    if (elapsed == 9999) {
      // Won't elapse further, so switch to stop mode
      mode = 2;
    }
  }
}
