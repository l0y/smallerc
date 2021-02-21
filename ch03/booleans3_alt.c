#include <stdio.h>

int main() {
  if (1 == 1)
    printf(" 1 == 1\n");
  else
    printf(" *** Yikes! 1 == 1 returned false\n");
  if (1 != 1)
    printf(" *** Yikes! 1 != 1 returned true\n");
  else
    printf(" 1 != 1  is false\n");
  if (5 < 10)
    printf(" 5 < 10\n");
  else
    printf(" *** Yikes! 5 < 10 returned false\n");
  if (5 > 10)
    printf(" *** Yikes! 5 > 10 returned true\n");
  else
    printf(" 5 > 10  is false\n");
  if (12 <= 10)
    printf(" *** Yikes! 12 <= 10 returned false\n");
  else
    printf("12 <= 10 is false\n");
  if (12 >= 10)
    printf("12 >= 10\n");
  else
    printf(" *** Yikes! 12 >= 10 returned false\n");
}