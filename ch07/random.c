#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("RAND_MAX: %d\n", RAND_MAX);
  unsigned int r1 = rand();
  printf("First random number: %d\n", r1);
  srand(5);
  printf("Second random number: %d\n", rand());
  srand(time(NULL));
  printf("Third random number: %d\n", rand());
  unsigned int pin = rand() % 9000 + 1000;
  printf("Random four digit number: %d\n", pin);
}