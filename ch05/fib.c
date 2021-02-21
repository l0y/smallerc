#include <stdio.h>

int fibonacci(int n) {
  // Base case 0
  // We'll lazily return zero for negative numbers as well
  if (n <= 0) {
    return 0;
  }
  // Base case 1
  if (n == 1) {
    return 1;
  }

  // recursive call
  return (fibonacci(n-1) + fibonacci(n-2));
}

int main() {
  printf("The 6th Fibonnaci number is: %d\n", fibonacci(6));
  printf("The 42nd Fibonnaci number is: %d\n", fibonacci(42));
  printf("The first 10 Fibonacci nubmers are:\n");
  for (int f = 0; f < 10; f++) {
    printf("  %d", fibonacci(f));
  }
  printf("\n");
}
