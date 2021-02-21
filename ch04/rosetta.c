#include <stdio.h>

int main() {
  char base;
  int input;
  printf("Convert from? (d)ecimal, (o)ctal, he(x): ");
  scanf("%c", &base);
  if (base == 'o') {
    // Get octal input
    printf("Please enter a number in octal: ");
    scanf("%o", &input);
  } else if (base == 'x') {
    // Get hex input
    printf("Please enter a number in hexadecimal: ");
    scanf("%x", &input);
  } else {
    // assume decimal input
    printf("Please enter a number in decimal: ");
    scanf("%d", &input);
  }
  printf("Dec: %d,  Oct: %o,  Hex: %x\n", input, input, input);
}