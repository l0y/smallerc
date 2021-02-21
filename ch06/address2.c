#include <stdio.h>

int main() {
  int answer = 42;
  double pi = 3.1415926;
  int extra = 1234;
  printf("answer's value: %d\n", answer);
  printf("answer's address: %p\n", &answer);
  printf("pi's value: %0.4f\n", pi);
  printf("pi's address: %p\n", &pi);
  printf("extra's value: %d\n", extra);
  printf("extra's address: %p\n", &extra);
}