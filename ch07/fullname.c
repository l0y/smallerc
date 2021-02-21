#include <stdio.h>
#include <string.h>

int main() {
  char first[20];
  char middle[20];
  char last[20];
  char full[60];
  char spacer[2] = " ";

  printf("Please enter your first name: ");
  scanf("%s", first);
  printf("Please enter your middle name or initial: ");
  scanf("%s", middle);
  printf("Please enter your last name: ");
  scanf("%s", last);

  // First, assemble the full name
  strncpy(full, first, 20);
  strncat(full, spacer, 40);
  strncat(full, middle, 39);
  strncat(full, spacer, 20);
  strncat(full, last, 19);

  printf("Well hello, %s!\n", full);

  int dennislen = 17;  // length of "Dennis M. Ritchie"
  if (strlen(full) == dennislen && 
      strncmp("Dennis M. Ritchie", full, dennislen) == 0)
  {
    printf("Thanks for writing C!\n");
  }
}