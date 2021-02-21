#include <stdio.h>

void print_average(float a, float b) {
  float average = (a + b) / 2;
  printf("The average of %.2f and %.2f is %.2f\n", a, b, average);
}

int main() {
  float num1, num2;
  printf("Please enter two numbers separated by a space: ");
  scanf("%f %f", &num1, &num2);
  print_average(num1, num2);

  float x = 17.17;
  float y = 6.2;
  print_average(3.1415, 2.71828);
  print_average(x, y);
  print_average(x * x, y * y);
  print_average(x, 3.1415);
}