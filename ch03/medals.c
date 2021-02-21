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
  }
}