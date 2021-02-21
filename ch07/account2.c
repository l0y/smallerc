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

void add_interest(struct account *acct, double rate, int months) {
  // Put our current balance in a local var for easier use
  double principal = acct->balance;
  // Convert our annual rate to a monthly percentage value
  rate /= 1200;
  // Use the interest formula to calculate our new balance
  acct->balance = principal * pow(1 + rate, months);
}

int main() {
  struct account *checking;
  checking = create("Bank of Earth (checking)", 200.0);
  print(checking);

  add_interest(checking, 5.0, 12);
  print(checking);

  free(checking);
}
