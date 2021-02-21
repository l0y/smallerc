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
  // The column labels are easy, just print them first.
  // Be sure to leave space for where the row labels will go.
  printf("  "); // At most two numbers in the row label
  for (int label = 1; label <= tableSize; label++) {
    printf("%4d", label);
  }
  printf("\n"); // Move to a fresh line for the table
  for (int row = 1; row <= tableSize; row++) {
    // Before we start the regular table cells, print the row label
    printf("%2d", row);
    // Now print the usual column entries
    for (int col = 1; col <= tableSize; col++) {
      printf("%4d", row * col);
    }
    printf("\n");
  }
}