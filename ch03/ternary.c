#include <stdio.h>

int main() {
  int bid1, bid2;
  printf("Enter two bids in whole dollars, separated by a space: ");
  scanf("%d %d", &bid1, &bid2);
  int winner = bid1 < bid2 ? bid1 : bid2;
  printf("The winning bid is: %d\n", winner);
}