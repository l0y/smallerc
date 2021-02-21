#include <stdio.h>

int main() {
  int grade;
  float total = 0.0;
  int count = 0;
  do {
    printf("Enter a grade between 1 and 100 (0 to quit): ");
    scanf("%i", &grade);
    if (grade >= 1 && grade <= 100) {
      // Valid! Count it.
      total += grade;
      count++;
    } else if (grade != 0) {
      // Not valid, and not our sentinel, so print an error and continue.
      printf("   *** %d is not a valid grade. Skipping.\n", grade);
    }
  } while (grade != 0);

  if (count > 0) {
    printf("\nThe final average is %.2f\n", total / count);
  } else {
    printf("\nNo grades were entered.\n");
  }
}