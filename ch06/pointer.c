#include <stdio.h>

int main() {
  double total = 500.0;
  int count = 34;
  double average = total / count;
  printf("The average of %d units totalling %.1f is %.2f\n",
     count, total, average);

  // Now let's reproduce some of that work with pointers
  double *total_ptr = &total;
  int *count_ptr = &count;
  printf("total_ptr is the same as the address of total:\n");
  printf("  total_ptr %p == %p &total\n", total_ptr, &total);

  // We can manipulate the value at the end of a pointer
  // with the '*' prefix (dereferencing)
  printf("The current total is: %.1f\n", *total_ptr);
  // Let's pretend we forgot two units and correct our count:
  *count_ptr += 2;
  average = *total_ptr / *count_ptr;
  printf("The corrected average of %d units totalling %.1f is %.2f\n",
     count, total, average);
}