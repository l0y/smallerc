#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct account {
  char name[50];
  double balance;
};

struct account *create(char *name, double initial) {
  struct account *acct = malloc(sizeof(struct account));
  strncpy(acct->name, name, 49);
  acct->balance = initial;
  return acct;
}

void print(struct account *a) {
  printf("Account: %s\n", a->name);
  printf("Balance: $%.2f\n", a->balance);
}

int main() {
  struct account *checking;
  checking = create("Bank of Earth (checking)", 200.0);
  print(checking);
  free(checking);
}
