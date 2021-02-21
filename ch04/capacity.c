#include <stdio.h>

int main() {
  double ledger[100];
  printf("Size of a double: %li\n", sizeof (double));
  printf("Size of ledger: %li\n", sizeof ledger);
  printf("Calculated ledger capacity: %li\n", (sizeof ledger) / (sizeof (double)));
}