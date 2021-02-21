#include <stdio.h>

int main() {
  // Our string of characters to decode. Could prompt the user as well, of course.
  char source[] = "2P/g/xAARkpG";

  // Quick print of our source string
  printf("%s ==> ", source);

  // Pretend we don't know we need 9 bytes and be ready to store more
  unsigned char data[60];
  unsigned int index = 0; // index of where we are at in our decoded data

  // Get the length of our source (minus the final null char of the string)
  int source_length = sizeof(source) - 1;

  // Now we reverse the encoding process. Take four 6-bit chunks of source
  // and turn them into three 8-bit chunks of binary data
  for (int s = 0; s < source_length; s += 4) {
    // "undo" the translation if-else-if chain into a buffer
    unsigned char buffer[4];
    for (int b = 0; b < 4; b++) {
      char src = source[s + b]; // grab the current source byte
      if (src >= 'A' && src <= 'Z') {
        // uppercase letter, so value 0 - 25
        buffer[b] = src - 'A';
      } else if (src >= 'a' && src <= 'z') {
        // lowercase letter, so value 26 - 51
        buffer[b] = src - 'a' + 26;
      } else if (src >= '0' && src <= '9') {
        // a digit, so value 52 - 61
        buffer[b] = src - '0' + 52;
      } else if (src == '+') {
        // our "+" case, no need for math, just assign 62
        buffer[b] = 62;
      } else if (src == '/') {
        // our "/" case, no need for math, just assign 63
        buffer[b] = 63;
      } else {
        // Yikes! Error. We should never get here.
        printf("\n\n Error! Bad 6-bit value: %c\n", src);
      }
    }

    // "byte1" gets all of the first source char and two bits from the second
    data[index] = buffer[0] << 2;
    data[index] |= (buffer[1] & 0x30) >> 4;

    // "byte2" gets the rest of the second char and four bits from the third
    data[index + 1] = (buffer[1] & 0x0f) << 4;
    data[index + 1] |= (buffer[2] & 0x3c) >> 2;

    // "byte3" gets the rest of the third char and all six bits of the fourth
    data[index + 2] = (buffer[2] & 0x03) << 6;
    data[index + 2] |= buffer[3] & 0x3f;

    // And finally, bump our data index up to get ready for the next three
    // 8-bit values
    index += 3;
  }
  
  // Print out our results. Luckily index also marks the length of data[]
  for (int i = 0; i < index; i++) {
    printf("0x%02x ", data[i]);
  }
  printf("\n");
}