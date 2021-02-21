#include <stdio.h>

int main() {
  printf(" Dec  Oct  Hex\n");
  for (int i = 0; i < 16; i++) {
    printf(" %3d  %03o   0x%02X\n", i, i, i);
  }
}