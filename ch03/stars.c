#include <stdio.h>

int main() {
  int score = 0;
  printf("Enter your score (1 - 100): ");
  scanf("%d", &score);
  if (score > 100) {
    printf("Bad score, must be between 1 and 100.\n");
  } else if (score >= 85) {
    printf("Great! 3 stars!\n");
  } else if (score >= 50) {
    printf("Good score! 2 stars.\n");
  } else if (score >= 1) {
    printf("You completed the game. 1 star.\n");
  } else {
    // Only here because we have a negative score
    printf("Impossible score, must be positive.\n");
  }
}