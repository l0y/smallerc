#include <stdio.h>
#include <string.h>

int main() {
  char background[20];
  printf("Enter a background color or return for the default: ");
  scanf("%[^\n]s", background);
  if (strlen(background) == 0) {
    strcpy(background, "black");
  }
  printf("The background color is now %s.\n", background);
}