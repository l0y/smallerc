#include <stdio.h>

int main() {
  printf("This is a typical print statement.\n");
  int total_bytes = printf("This is also a print statement.\n");
  printf("The previous printf displayed %d bytes.\n", total_bytes);
}