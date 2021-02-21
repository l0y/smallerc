#include <stdio.h>

void print_help() {
  printf("This program prints a friendly greeting.\n");
  printf("When prompted, you can type in a name \n");
  printf("and hit the return key. Max length is 24.\n");
}

void greet(char name[]) {
  printf("Hello, %s\n", name);
}

int main() {
  char name[25];

  // First, tell them how to use the program
  print_help();

  // Now, prompt them for a name (just the once)
  printf("Please enter your name: ");
  scanf("%s", name);

  // Finally, call our new greeting function with our name argument
  greet(name);
}