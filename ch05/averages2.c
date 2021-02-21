#include <stdio.h>

float calc_average(float a, float b) {
  return (a + b) / 2;
}

int main() {
  float avg = calc_average(12.34, 56.78);
  float triple = 3 * calc_average(3.14, 1.414);
  printf("The first average is %.2f\n", avg);
  printf("Our tripled average is %.2f\n", triple);
  printf("A direct average: %.2f\n", calc_average(8, 12));
}
