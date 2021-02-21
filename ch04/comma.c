#include <stdio.h>

int main() {
  char phrase[] = "Hello, world!";
  int i = 0;
  // keep looping until the end of the string
  while (phrase[i] != '\0') {
    if (phrase[i] == ',') {
      printf("Found a comma at position %d.\n", i);
      break;
    }
    // try the next character
    i++;
  }
  if (phrase[i] == '\0') {
    // Rats. Made it to the end of the string without a match.
    printf("No comma found in %s\n", phrase);
  }
}