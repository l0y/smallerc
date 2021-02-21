#include <stdio.h>

void increment_me(int me, int amount) {
  // increment "me" by the "amount"
  me += amount;
  printf("  Inside increment_me: %d\n", me);
}

void increment_me_too(int *me, int amount) {
  // increment the variable pointed to by "me" by the "amount"
  *me += amount;
  printf("  Inside increment_me_too: %d\n", *me);
}

int main() {
  int count = 1;
  printf("Initial count: %d\n", count);
  increment_me(count, 5);
  printf("Count after increment_me: %d\n", count);
  increment_me_too(&count, 5);
  printf("Count after increment_me_too: %d\n", count);
}
