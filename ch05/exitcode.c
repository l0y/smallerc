#include <stdio.h>

int main() {
  char answer;
  printf("Would you like to succeed (s) or fail (f)? ");
  scanf("%c", &answer);
  if (answer == 's') {
    return 0;
  } else if (answer == 'f') {
    return 1;
  } else {
    printf("You supplied an unsupported answer: %c\n", answer);
    return 2;
  }
}
