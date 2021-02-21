#include <stdio.h>

int main() {
  int input;
  printf("Please enter a number using C prefixes for octal (0) and hex (0x): ");
  scanf("%i", &input);
  printf("Dec: %d,  Oct: %o,  Hex: %x\n", input, input, input);
}