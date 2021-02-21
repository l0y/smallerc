#include <stdio.h>

int main() {
  int num1, num2, num3;
  printf("Please enter three numbers, separated by a space: ");
  scanf("%d %d %d", &num1, &num2, &num3);
  printf("%d + %d + %d is %d\n", num1, num2, num3, num1 + num2 + num3);
  printf("%d + %d - %d is %d\n", num1, num2, num3, num1 + num2 - num3);
  printf("%d * %d / %d is %d\n", num1, num2, num3, num1 * num2 / num3);
  printf("%d + %d / %d is %d\n", num1, num2, num3, num1 + num2 / num3);
  printf("%d * %d %% %d is %d\n", num1, num2, num3, num1 * num2 % num3);
}