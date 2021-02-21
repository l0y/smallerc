#include <stdio.h>

int main() {
  printf("Print only even values from 2 to 10:\n");
  for (int i = 2; i <= 10; i = i + 2) {
    printf("  %i\n", i);
  }
  printf("\nCount down from 5 to 1:\n");
  for (int j = 5; j > 0; j = j - 1) {
    printf("  %i\n", j);
  }
}