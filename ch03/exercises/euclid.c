#include <stdio.h>

int main() {
  int a, b;
  printf("Enter two positive integers, separated by a space: ");
  scanf("%d %d", &a, &b);
  // print back a and b before we start changing them in our loop
  printf("The greatest common divisor of %d and %d is ", a, b);
  while (b != 0) {
    if (a > b) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  printf("%d.\n", a);
}