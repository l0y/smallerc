#include <stdio.h>

int main() {
  int num1, num2;
  printf("Please enter two numbers, separated by a space: ");
  scanf("%d %d", &num1, &num2);
  printf("%d + %d is %d\n", num1, num2, num1 + num2);
  printf("%d - %d is %d\n", num1, num2, num1 - num2);
  printf("%d * %d is %d\n", num1, num2, num1 * num2);
  printf("%d / %d is %d\n", num1, num2, num1 / num2);
  printf("%d %% %d is %d\n", num1, num2, num1 % num2);
}