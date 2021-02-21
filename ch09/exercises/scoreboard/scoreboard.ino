#include <TM1637Display.h>

#define CLK       6
#define DIO       7

#define LEFT_INC_BUTTON  11
#define LEFT_DEC_BUTTON  10
#define RIGHT_INC_BUTTON  3
#define RIGHT_DEC_BUTTON  2

// Create our 4-segment display object
TM1637Display display(CLK, DIO);

// Keep score (0-99) for two teams
byte leftScore  = 0;
byte rightScore = 0;

// Track the state for our four buttons
byte leftIncState  = HIGH;
byte leftDecState  = HIGH;
byte rightIncState = HIGH;
byte rightDecState = HIGH;

void updateScores() {
  display.showNumberDecEx(leftScore,0,false,2,0);
  display.showNumberDecEx(rightScore,0,false,2,2);
}

void setup() {
  // Get our button pins ready
  pinMode(LEFT_INC_BUTTON, INPUT_PULLUP);
  pinMode(LEFT_DEC_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_INC_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_DEC_BUTTON, INPUT_PULLUP);

  // And set up the scoreboard
  display.clear();
  display.setBrightness(0x0f);
  updateScores();
}

void loop() {
  // Check our buttons
  byte leftInc = digitalRead(LEFT_INC_BUTTON);
  byte leftDec = digitalRead(LEFT_DEC_BUTTON);
  byte rightInc = digitalRead(RIGHT_INC_BUTTON);
  byte rightDec = digitalRead(RIGHT_DEC_BUTTON);

  // Did any of the buttons "fall"?
  if (leftInc == LOW && leftIncState == HIGH) {
    leftScore = constrain(leftScore + 1, 0, 99);
  }
  if (leftDec == LOW && leftDecState == HIGH) {
    leftScore = constrain(leftScore - 1, 0, 99);
  }
  if (rightInc == LOW && rightIncState == HIGH) {
    rightScore = constrain(rightScore + 1, 0, 99);
  }
  if (rightDec == LOW && rightDecState == HIGH) {
    rightScore = constrain(rightScore - 1, 0, 99);
  }

  // Make sure all of the button states are current
  leftIncState = leftInc;
  leftDecState = leftDec;
  rightIncState = rightInc;
  rightDecState = rightDec;

  // Finally, update our scores
  updateScores();
  delay(10);
}
