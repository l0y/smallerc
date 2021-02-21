#include <stdio.h>

int main() {
  char title[30] = "Address Example 3";
  int page_counts[5] = { 14, 78, 49, 18, 50 };
  printf("title's value: %s\n", title);
  printf("title's address: %p\n", &title);
  printf("title's size: %lu\n", sizeof(title));
  printf("page_counts' value: {");
  for (int p = 0; p < 5; p++) {
    printf(" %d", page_counts[p]);
  }
  printf(" }\n");
  printf("page_counts's address: %p\n", &page_counts);
  printf("page_counts's size: %lu\n", sizeof(page_counts));
}