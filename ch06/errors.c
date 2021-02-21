#include <stdio.h>
#include <stdlib.h>

struct point {
  int x, y;
};

int main() {
  // Make a few pointers and force some errors to illustrate
  // what might go wrong in a real program.

  // Declare a few coordinates and pointers
  struct point coord = { 5, 12 };
  struct point *ptr1 = (struct point *)malloc(sizeof(struct point));
  struct point *ptr2 = NULL;

  // The coord local variable is always safe:
  printf("First coordinate is: (%d, %d)\n", coord.x, coord.y);

  // The second pointer will always crash:
  //printf("Last coordinate is empty: (%d, %d)\n", ptr2->x, ptr2->y);

  // The middle pointer has space, but hasn't been properly initialized.
  // It might have zeroes, but it might have random junk.
  printf("The middle coordinate will be random: (%d, %d)\n", ptr1->x, ptr1->y);

  // Best to give it some intentional values:
  ptr1->x = 25;
  ptr1->y = 30;
  printf("The middle coordinate after assignment: (%d, %d)\n", ptr1->x, ptr1->y);

  // Let's free the middle pointer and see what happens if we try to use it afterwards:
  free(ptr1);
  // We might get away with using it
  printf("The middle coordinate after free(): (%d, %d)\n", ptr1->x, ptr1->y);
}