#include <stdio.h>
#include <stdlib.h>

void confirm() {
  char answer;
  printf("Are you sure you want to exit? (y/n) ");
  scanf("%c", &answer);
  if (answer == 'y' || answer == 'Y') {
    printf("Bye\n\n");
    exit(0);
    printf("This will never be printed.\n");
  }
}

int main() {
  printf("In main... let's try exiting.\n");
  confirm();
  printf("Glad you decided not to leave.\n");
}