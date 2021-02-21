#include <stdio.h>

int main() {
  char name[20];
  
  printf("Enter your name: ");
  scanf("%s", name);
  printf("Well hello, %s!\n", name);
}