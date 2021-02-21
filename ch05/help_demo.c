#include <stdio.h>

void print_help() {
  printf("This program prints a friendly greeting.\n");
  printf("When prompted, you can type in a name \n");
  printf("and hit the return key. Max length is 24.\n");
}

int main() {
  char name[25];

  do {
    // Call our newly minted help function!
    print_help();

    // Now prompt the user, but if they enter an 'h',
    // start over with the help message
    printf("Please enter a name: ");
    scanf("%s", name);
  } while (name[0] == 'h' && name[1] == '\0');

  // Ok, we must have a name to greet!
  printf("Hello, %s!\n", name);
}