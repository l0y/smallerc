#include <stdio.h>

int main() {
  int place;
  printf("Enter your place: ");
  scanf("%i", &place);
  switch (place) {
  case 1:
    printf("1st place! Gold!\n");
    break;
  case 2:
    printf("2nd place! Silver!\n");
    break;
  case 3:
    printf("3rd place! Bronze!\n");
    break;
  case 4:
  case 5:
    printf("You're a runner up!\n");
    break;
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
    printf("Top 10! Congrats!\n");
    break;
  default:
    printf("Sorry, you didn't make the podium.\n");
  }
}
