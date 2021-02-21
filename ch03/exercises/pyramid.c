#include <stdio.h>

int main() {
  int pyramidBase;
  printf("Please enter a size for your pyramid (1 - 20): ");
  scanf("%i", &pyramidBase);
  if (pyramidBase < 1 || pyramidBase > 20) {
    printf("We can't make a pyramid that size. Sorry!\n");
    printf("We'll use the default size of 10 instead.\n");
    pyramidBase = 10;
  }
  // Notice that since we declared row and col above, we do *not*
  // include the "int" type declaration inside the for loops below
  for (int row = 1; row <= pyramidBase; row++) {
    // First figure out how much padding we need
    int padding = pyramidBase - row;
    // Next, get the padding printed
    for (int p = 0; p < padding; p++) {
      printf(" ");
    }
    // Now print the stars with spaces to make centering easy
    for (int col = 1; col <= row; col++) {
      printf("* ");
    }
    printf("\n");
  }
}