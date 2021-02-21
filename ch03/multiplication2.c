#include <stdio.h>

int main() {
  int tableSize;
  printf("Please enter a size for your table (1 - 20): ");
  scanf("%i", &tableSize);
  if (tableSize < 1 || tableSize > 20) {
    printf("We can't make a table that size. Sorry!\n");
    printf("We'll use the default size of 10 instead.\n");
    tableSize = 10;
  }
  for (int row = 1; row <= tableSize; row++) {
    // row and tableSize are both in scope
    for (int col = 1; col <= tableSize; col++) {
      // row, col, and tableSize are all in scope
      printf("%4d", row * col);
    }
    // col is now *out* of scope
    printf("\n"); // final newline to move to the next row
  }
  // row is out of scope now, too, but tableSize remains available
}