#include <stdio.h>

int main() {
  char name[] = "a.c. Programmer";
  printf("Before manipulation: %s\n", name);
  // Let's use pointer math to directly change the initials to uppercase
  *name = 'A';
  *(name + 2) = 'C';
  printf("After manipulation: %s\n", name);
}