#include <stdio.h>

void print_help(char *program_name) {
  printf("You can enter several command-line arguments like this:\n");
  printf("%s this is four words\n", program_name);
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    printf("Only the name of the program '%s' was given.\n", argv[0]);
  } else if (argc == 2) {
    // Might be a request for help
    int len = sizeof(argv[1]);
    if (len >= 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
      print_help(argv[0]);
    } else {
      printf("Found one, non-help argument: %s\n", argv[1]);
    }
  } else {
    printf("Found %c command-line arguments:\n", argc);
    for (int i = 0; i < argc; i++) {
      printf("  %s\n", argv[i]);
    }
  }
}