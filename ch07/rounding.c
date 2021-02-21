#include <stdio.h>
#include <math.h>

int main() {
  int grades[6] = { 86, 97, 77, 76, 85, 90 };
  int total = 0;
  int average;

  for (int g = 0; g < 6; g++) {
    total += grades[g];
  }
  printf("Raw average: %0.2f\n", total / 6.0);
  average = (int)floor(total / 6.0 + 0.5);
  printf("Rounded average: %d\n", average);
}