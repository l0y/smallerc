#include <stdio.h>

char buffer[30];

void all_caps() {
  char buffer[30] = "This is a local buffer!";
  char diff = 'a' - 'A';
  for (int b = 0; b < 30 && buffer[b] != 0; b++) {
    if (buffer[b] >= 'a' && buffer[b] <= 'z') {
      // We have a lowercase letter, so change this slot
      // in the char array to its uppercase cousin
      buffer[b] -= diff;
    }
  }
  printf("Inside all_caps(): %s\n", buffer);
}

int main() {
  printf("Please enter a name or phrase: ");
  scanf("%[^\n]s", buffer);
  printf("Before all_caps(): %s\n", buffer);
  all_caps();
  printf("After all_caps(): %s\n", buffer);
}