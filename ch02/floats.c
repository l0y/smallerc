#include <stdio.h>

int main() {
  float one_half = 0.5;
  double two_thirds = 0.666666667;
  double pi = 3.1415926535897932384626433;
  // Naive, unformated printing
  printf("1/2: %f\n", one_half);
  printf("2/3: %f\n", two_thirds);
  printf("pi:  %f\n", pi);

  // Better formatting with width and precision
  printf("1/2: |%5.2f|\n", one_half);
  printf("2/3: |%12f|\n", two_thirds);
  printf("pi:  |%12.10f|\n", pi);

  printf("int w precision: |%4.2i|\n", 18);
  printf("int w precision: |%4.2i|\n", 183);
  printf("int w precision: |%4.2i|\n", 1836);
  printf("int w precision: |%4.2i|\n", 11836);

  printf("%f\n", 1.0 / 3.0);
  printf("%f\n", (5 + 12) / 2.0);
}
