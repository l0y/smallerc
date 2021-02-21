// Include the usual stdio, but also stdlib for access
// to the malloc() and free() functions, and NULL
#include <stdio.h>
#include <stdlib.h>

// We can use the struct keyword to define new, composite types
struct transaction {
  double amount;
  int month, day, year;
};

// That new type can be used with function parameters
void printTransaction1(struct transaction tx) {
  printf("%2d/%02d/%4d: %10.2f\n", tx.month, tx.day, tx.year, tx.amount);
}

// We can also use a pointer to that type with parameters
void printTransaction2(struct transaction *ptr) {
  // Check to make sure our pointer isn't empty
  if (ptr == NULL) {
    printf("Invalid transaction.\n");
  } else {
    // Yay! We have a transaction, print out its details with ->
    printf("%2d/%02d/%4d: %10.2f\n", ptr->month, ptr->day, ptr->year, ptr->amount);
  }
}

// Passing a structure pointer to a function means we can alter
// the contents of the structure if necessary
void addTax(struct transaction *ptr, double rate) {
  double tax = ptr->amount * rate;
  ptr->amount += tax;
}

int main() {
  // We can declare local (or global) variables with our new type
  struct transaction bill;

  // We can assign initial values inside curly braces
  struct transaction deposit = { 200.00, 6, 20, 2021 };

  // Or we can assign values at any time after with the dot operator
  bill.amount = 56.75;
  bill.month = 7;
  bill.day = 15;
  bill.year = 2021;

  // We can pass structure variables to functions just like other variables
  printTransaction1(deposit);
  printTransaction1(bill);

  // We can also create pointers to structures and use them with malloc()
  struct transaction tmp = { 68.91, 8, 1, 2020 };
  struct transaction *payment = NULL;
  struct transaction *withdrawal;
  payment = &tmp;
  withdrawal = malloc(sizeof(struct transaction));

  // With a pointer, we either have to carefully dereference it
  (*withdrawal).amount = -20.0;
  // Or use the arrow operator
  withdrawal->day = 3;
  withdrawal->month = 8;
  withdrawal->year = 2021;

  // And we are free to pass structure pointers to functions
  printTransaction2(payment);
  printTransaction2(withdrawal);

  // Add tax to our bill using a function and a pointer
  printf("Our bill amount before tax: $%.2f\n", bill.amount);
  addTax(&bill, 0.05);
  printf("Our bill amount after tax: $%.2f\n", bill.amount);

  // Before we go, release the memory we allocated to withdrawal:
  free(withdrawal);
}