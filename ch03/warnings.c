#include <stdio.h>

int main() {
  int units = 0;
  printf("Please enter the number of units found: ");
  scanf("%d", &units);
  if (units < 0) {
    printf("  *** Warning: possible lost items ***\n");
  }
  printf("%d units received.\n", units);
}