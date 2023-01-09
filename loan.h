#ifndef LOAN_GUARD__H
#define LOAN_GUARD__H
#include "util.h"
#include "date.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
typedef struct LoanedBooks{
  char *author;
  char *title;
  unsigned int year;
}Loaned;

typedef struct MakeALoan{
  Loaned loaned_books;
  Date loan_date;
  Date return_loan;
}Loan;
typedef struct LoanedBooksArray{
  Loan *array;//array of loans
  int length;//number of loans
}LoanedArray;
//similarly to the book_management functions
//these function find a loan according to the given parameters
void add_loan_to_array(LoanedArray *loanedArray,Loan loan);
void remove_loan(LoanedArray *loanedArray,Loan loan);
Loan askForLoan();


bool equalLoan(Loaned book1,Loaned book2);
int findLoan(Loan loan,LoanedArray *loanArray);
#endif
