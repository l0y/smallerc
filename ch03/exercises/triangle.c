#include <stdio.h>

int main() {
  int triangleSize;
  printf("Please enter a size for your triangle (1 - 20): ");
  scanf("%i", &triangleSize);
  if (triangleSize < 1 || triangleSize > 20) {
    printf("We can't make a triangle that size. Sorry!\n");
    printf("We'll use the default size of 10 instead.\n");
    triangleSize = 10;
  }
  // Notice that since we declared row and col above, we do *not*
  // include the "int" type declaration inside the for loops below
  for (int row = 1; row <= triangleSize; row++) {
    for (int col = 1; col <= row; col++) {
      printf("*");
    }
    printf("\n");
  }
}