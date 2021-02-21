#include <stdio.h>

int str2int(char *digits) {
  int end = -1;
  // Find the end of our string
  while (digits[end + 1] != '\0') {
    end++;
  }

  // Now comes the fun. Convert the right-most digit to a number using
  // simple ASCII math. Then get the next right-most digit. Convert it,
  // but also multiply it by 10. Then the third multiplied by 100. Etc.
  int multiplier = 1;
  int result = 0;
  for (int d = end; d >= 0; d--) {
    if (digits[d] >= '0' && digits[d] <= '9') {
      // Great. We have a valid numeric character
      int asNumber = digits[d] - '0';

      // Add it to the result with the correct power of 10 applied
      result += (asNumber * multiplier);

      // And get the multiplier ready for the next digit
      multiplier *= 10;
    } else {
      // Oops, hit a non-numeric character. Stop converting.
      break;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  int total = 0;
  for (int i = 1; i < argc; i++) {
    total += str2int(argv[i]);
  }
  printf("The sum of these %d numbers is %d\n", argc - 1, total);
}