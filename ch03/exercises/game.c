#include <stdio.h>

int main() {
  int secret = 42;
  int guess;
  do {
    printf("Guess a number between 1 and 50: ");
    scanf("%d", &guess);
    if (guess < secret) {
      printf("Too low! Try again.\n");
    } else if (guess > secret) {
      printf("Too high! Try again.\n");
    }
  } while (guess != secret);
  printf("*** Congratulations! You got it right! ***\n");
}