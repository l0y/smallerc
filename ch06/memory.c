#include <stdio.h>
#include <stdlib.h>

int result_code = 404;
char result_msg[20] = "File Not Found";

int main() {
  char temp[20] = "Loading ...";
  int success = 200;

  char *buffer = (char *)malloc(20 * sizeof(char));

  // We won't do anything with these various variables,
  // but we can print out their addresses
  printf("Address of result_code:   %p\n", &result_code);
  printf("Address of result_msg:    %p\n", &result_msg);
  printf("Address of temp:          %p\n", &temp);
  printf("Address of success:       %p\n", &success);
  printf("Address of buffer (heap): %p\n", buffer);
}