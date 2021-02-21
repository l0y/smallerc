#include <stdio.h>

int main() {
  int grade;
  float total = 0.0;
  int count = 0;
  printf("Please enter a grade between 1 and 100. Enter 0 to quit: ");
  scanf("%i", &grade);
  while (grade != 0) {
    total += grade;
    count++;
    printf("Enter another grade (0 to quit): ");
    scanf("%i", &grade);
  }
  if (count > 0) {
    printf("\nThe final average is %.2f\n", total / count);
  } else {
    printf("\nNo grades were entered.\n");
  }
}