#include <stdio.h>

// What happens if we don't use a break with our switch cases?

int main() {
  int place;
  printf("Enter your place: ");
  scanf("%i", &place);
  switch (place) {
  case 1:
    printf("1st place! Gold!\n");
  case 2:
    printf("2nd place! Silver!\n");
  case 3:
    printf("3rd place! Bronze!\n");
  }
}