#include <stdio.h>

int main() {
  int grade;
  float total = 0.0;
  int count = 0;
  do {
    printf("Enter a grade between 1 and 100 (0 to quit): ");
    scanf("%i", &grade);
    total += grade;
    count++;
  } while (grade != 0);
  // We end up counting the sentinel as a grade, so undo that
  count--;

  if (count > 0) {
    printf("\nThe final average is %.2f\n", total / count);
  } else {
    printf("\nNo grades were entered.\n");
  }
}