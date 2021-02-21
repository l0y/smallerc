#include <stdio.h>

int main() {
  char automatic[] = "A string variable with just the right length";
  char jobtitle[50] = "Chief Acceptable Length Officer";
  char warning[5] = "This is a bad idea.";
  printf("Ahem!\n");
  printf("May I have your attention, please?\n");
  printf("I would like to extend the warmest of\n");
  printf("greetings to the world.\n");
  printf("Thank you. %s (%li)\n", warning, sizeof(warning));
}
