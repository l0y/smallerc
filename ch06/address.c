#include <stdio.h>

int main() {
  int answer = 42;
  double pi = 3.1415926;
  printf("answer's value: %d\n", answer);
  printf("answer's address: %p\n", &answer);
  printf("pi's value: %0.4f\n", pi);
  printf("pi's address: %p\n", &pi);
}