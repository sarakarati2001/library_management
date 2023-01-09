
#include "loan.h"
#include "util.h"
#include "date.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

//similarly to the book_management functions
//these function find a loan according to the given parameters
void add_loan_to_array(LoanedArray *loanedArray,Loan loan){
  int i=0;
  Loan *array=(Loan*)malloc((loanedArray->length+1)*sizeof(Loan));
    if(array==NULL){
      return;
    }else{
      while(i<loanedArray->length){
        array[i]=loanedArray->array[i];
        i++;
      }
      array[i]=loan;
    }
    if(loanedArray->length!=0){
      free(loanedArray->array);
    }
    loanedArray->array=array;
    loanedArray->length++;
}
void remove_loan(LoanedArray *loanedArray,Loan loan){
  //check for position
  //and assign it to a variable
  int position=0;
  //in case position is -1;
  if(position==-1){
    printf("\t!********* Cannot find element at this index **********!\n");
    return;
  }
  int i;
  //start iterating from the current position through the whole array of loans
  for(i=position;i<loanedArray->length-1;i++){
    //shift the loans from right to left
    loanedArray->array[i]=loanedArray->array[i+1];
    //decrement the length of loans
    loanedArray->length--;
  }
}
Loan askForLoan(){
  //initialize new loan
  Loan newLoan;
  // printf("Enter the name of the book you want to loan:\n");
  // newLoan.loaned_books.title = enterDetails();
  // printf("Enter the author of the book you want to loan");
  // newLoan.loaned_books.author = enterDetails();
  printf("Enter the year of the book you to loan");
  scanf("%d",&newLoan.loaned_books.year);
  printf("The date you plan to return the book:");
  scanf("%2d/%2d/%4d",&newLoan.return_loan.day,&newLoan.return_loan.month,&newLoan.return_loan.year);
  if(!is_valid_date(newLoan.return_loan.day,newLoan.return_loan.month,newLoan.return_loan.year)){
    printf("!********** Error! Wrong inputs for the date **********!");
  }
  return newLoan;
}

int findLoan(Loan loan,LoanedArray *loanArray){
  for(int i=0;i<loanArray->length;i++){
    if(strcasecmp(loan.loaned_books.author,loanArray->array[i].loaned_books.author)==0
    &&strcasecmp(loan.loaned_books.title,loanArray->array[i].loaned_books.title)==0
    && loan.loaned_books.year==loanArray->array[i].loaned_books.year){
      return i;
      }
    }
  return -1;
}
bool equalLoan(Loaned book1,Loaned book2){
    if(strcasecmp(book1.title, book2.title) == 0 &&
       strcasecmp(book1.author, book2.author) == 0 &&
       book1.year == book2.year){
        return true;
    }
	return false;
}
// void return_loan(UsersArray *usersArray,Loan loan);
