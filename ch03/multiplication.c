#include <stdio.h>

int main() {
  int tableSize = 10;
  for (int row = 1; row <= tableSize; row++) {
    for (int col = 1; col <= tableSize; col++) {
      printf("%4d", row * col);
    }
    printf("\n"); // final newline to move to the next row
  }
}