#include <stdio.h>

int main() {
  int multiplication[5][5] = {
    {0, 0, 0, 0, 0},
		{0, 1, 2, 3, 4},
		{0, 2, 4, 6, 8},
		{0, 3, 6, 9, 12},
		{0, 4, 8, 12, 16}
  };

  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 5; col++) {
      printf("%3d", multiplication[row][col]);
    }
    printf("\n");
  }
}