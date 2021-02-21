#include <stdio.h>

int main() {
  // the array capacity and the length of its content match
  int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

  // capacity can be determined by the compiler to exactly contain the content
  char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
  float readings[] = { 8.9, 8.6, 8.5, 8.7, 8.9, 8.8, 8.5 };

  // or capacity can be larger than needed for the initial content, with room for growth
  float more_readings[10] = { 8.9, 8.6 };

  // While technically an array of char similar to vowles[] above, string
  // literals can be used to initialize these types of arrays:
  char secret[] = "password1";
  char downloads[] = "C:\\Downloads";

  // Use the square bracket notation to access individual elements
  printf("The second vowel is: %c\n", vowels[1]);
  printf("July has %d days.\n", days_in_month[6]);

  // You can use a variable or expression inside the square brackets
  int month = 7;
  printf("July (month %d) has %d days.\n", month, days_in_month[month - 1]);
  // But you should stay within the bounds of the array (0-11 in this case)
  month = 15;
  printf("Invalid (month %d) has %d days.\n", month, days_in_month[month - 1]);

  // You can assign values to slots in an array using the same square brackets:
  more_readings[7] = 8.4;
  // You do need to assign values that match the array's type
  more_readings[8] = 'x';
  printf("Good reading: %.1f, bad reading: %.1f\n", more_readings[7], more_readings[8]);

  // A loop can be used to access all of an array's elements serially
  for (int m = 0; m < 12; m++) {
    // remember the array starts at 0, but humans start at 1
    printf("Days in month %d is %d.\n", m + 1, days_in_month[m]);
  }

  // And you can calculate the length of an array at runtime if needed,
  // as long as you know what type the array is and are sure that is
  // completely filled--sizeof() reports capacity, not utilization:
  int count = sizeof(readings) / sizeof(float);

  // That dynamic count can enable fairly flexible behavior at runtime.
  // For example, we can calculate the average of however many readings
  // were initially stored without explicitly counting them ahead of time:
  float total = 0.0;
  float average;
  int smallestIndex = 0;     // start with the first index
  float largestValue = -1.0; // or start with an impossibly low value
  for (int r = 0; r < count; r++) {
    total += readings[r];
    if (readings[r] < readings[smallestIndex]) {
      // This reading is our smallest yet, so store it
      smallestIndex = r;
    }
    if (readings[r] > largestValue) {
      // This reading is our largest yet, so store it
      largestValue = readings[r];
    }
  }
  average = total / count;
  printf("The average reading is %0.2f\n", average);
  printf("The smallest value is %.1f (index %i)\n", readings[smallestIndex], smallestIndex);
  printf("The largest value is %.1f\n", largestValue);

}