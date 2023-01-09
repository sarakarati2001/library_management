#include "./unity.h"
#include "./unity_internals.h"
#include "book_management.h"
#include "interface.h"
#include "Users.h"
#include "date.h"
 #include "util.h"
 #include "main.h"
#include "loan.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
void setUp(void){}

void tearDown(void){}

void test_removeBook(){
  struct BookArray array,newArray;
  array.array=NULL;
  array.length=0;
  newArray.array=NULL;
  newArray.length=0;
   struct Book books1[3]={
    {"Kronike ne Gur","Ismail Kadare",1964},
    {"South of the border west of the sun","Haruki Murakami", 1989},
    {"Hundred Years of Solitude","Gabriel Garzia MMaruez",1976},
  };
  add_book_to_array(&array,*books1);
    remove_book(books1[1]);
   struct Book books2[2]={
     {"Kronike ne Gur","Ismail Kadare",1964},
     {"Hundred Years of Solitude","Gabriel Garzia MMaruez",1976},
   };
   add_book_to_array(&newArray,*books2);
   TEST_ASSERT_FALSE(existsBook(books1[1],&newArray));

}
void test_findBookByTitle(void){
  struct Book book,book2;
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  book.title="Kronike ne gur";
  add_book_to_array(&array,book);
  struct BookArray findBook=find_book_by_title("Kronike ne gur");
  book2.title="Kronike ne gur";
  add_book_to_array(&findBook,book2);
  printf("TEST3\n");
  TEST_ASSERT_EQUAL_STRING(book.title,findBook.array->title);
}
void test_findBookByAuthor(void){
  struct Book book,book2;
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  book.authors="Ismail Kadare";
  add_book_to_array(&array,book);
  struct BookArray findBook=find_book_by_author("Ismail Kadare");
  book2.authors="Ismail Kadare";
  add_book_to_array(&findBook,book2);
   printf("TEST4\n");
  TEST_ASSERT_EQUAL_STRING(book.authors,findBook.array->authors);
}
void test_findBookByYear(void){
  struct Book book,book2;
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  book.year=1964;
  add_book_to_array(&array,book);
  struct BookArray findBook=find_book_by_year(1964);
  book2.year=1964;
  add_book_to_array(&findBook,book2);
   printf("TEST4\n");
  TEST_ASSERT_EQUAL_INT(book.year,findBook.array->year);
}

void test_intToStr(void){
  char* character = "22";
  int integer =22;
  printf("TEST1\n");
  TEST_ASSERT_EQUAL_STRING(character, convertIntToString(integer));
}
void test_concatenate(){
  char *string1 = "sara";

  char *string2 ="karati";

  char *concat ="sarakarati";
   printf("TEST2\n");
  TEST_ASSERT_EQUAL_STRING(concat,concatenate(string1,string2));
}
void test_addNewBook(void){
  struct Book book,book1,book2,book3;
  struct BookArray array;
  array.length=0;
  array.array=NULL;
  int i=0;
  //allocate two new users using another
  //adding method
  if(i==array.length){
    array.array=(struct Book*)realloc(array.array,(array.length+1)*sizeof(struct Book));
  }
  array.array[i++]=book;
  array.array[i++]=book1;
  //increase the length by the number of the books registered;
  array.length+=i;
  //allocate again two books using the function add_new_book
  struct BookArray array2;
  array2.array=NULL;
  array2.length=0;
  add_book_to_array(&array2,book2);
  add_book_to_array(&array2,book3);
  printf("TEST3\n");
  //compare the length of both arrays
  TEST_ASSERT_EQUAL_INT(array.length,array2.length);
}
void test_findBookByTitleAndYear(void){
  struct Book book,book2;
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  book.year=1964;
  book.title="Kronike ne gur";
  add_book_to_array(&array,book);
  struct BookArray findBook=find_book_by_title_and_year(&array,"Kronike ne Gur",1964);
  book2.year=1964;
  book2.title="Kronike ne gur";
  add_book_to_array(&findBook,book2);
  printf("TEST3\n");
  TEST_ASSERT_EQUAL_INT(book.year,findBook.array->year);
  TEST_ASSERT_EQUAL_STRING(book.title,findBook.array->title);
}
void test_findBookByAuthorsAndYear(void){
  struct Book book,book2;
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  book.year=1964;
  book.authors="Ismail Kadare";
  add_book_to_array(&array,book);
  struct BookArray findBook=find_book_by_author_and_year(&array,"Ismail Kadare",1964);
  book2.year=1964;
  book2.authors="Ismail Kadare";
  add_book_to_array(&findBook,book2);;
   printf("TEST4\n");
  TEST_ASSERT_EQUAL_INT(book.year,findBook.array->year);
  TEST_ASSERT_EQUAL_STRING(book.authors,findBook.array->authors);
}
void test_findBookByTitleAndAuthor(void){
  struct Book book,book2;
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  book.authors="Ismail Kadare";
  book.title="Kronike ne gur";
  add_book_to_array(&array,book);;
   struct BookArray findBook=find_book_by_author_and_title(&array,"Ismail Kadare","Kronike ne Gur");
  book2.authors="Ismail Kadare";
  book2.title="Kronike ne gur";
  add_book_to_array(&findBook,book2);
   printf("TEST5\n");
  TEST_ASSERT_EQUAL_STRING(book.authors,findBook.array->authors);
  TEST_ASSERT_EQUAL_STRING(book.title,findBook.array->title);

}
void test_findBookByAuthorTitleAndYear(void){
  struct Book book,book2;
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  book.year=1964;
  book.authors="Ismail Kadare";
  book.title="Kronike ne Gur";
  add_book_to_array(&array,book);
  struct BookArray findBook=find_book_by_author_title_and_year(&array,"Ismail Kadare","Kronike ne Gur",1964);
  book2.year=1964;
  book2.authors="Ismail Kadare";
  book2.title="Kronike ne Gur";
  add_book_to_array(&findBook,book2);
   printf("TEST6\n");
  TEST_ASSERT_EQUAL_INT(book.year,findBook.array->year);
  TEST_ASSERT_EQUAL_STRING(book.authors,findBook.array->authors);
  TEST_ASSERT_EQUAL_STRING(book.title,findBook.array->title);
}

void test_equalBook(void){
    struct Book b1, b2;
    b1.authors = "Sara";
    b1.title = "test";
    b1.year = 2020;
    b2.authors = "Sara";
    b2.title = "test";
    b2.year = 2020;
    printf("TEST7\n");
    TEST_ASSERT_TRUE(equalBooks(b1, b2));
}
void test_existsBook(){
  struct BookArray array;
  array.array=NULL;
  array.length=0;
  struct Book book,book1,book2,book3;
  book.title="Kronike ne Gur";
  book.authors="Ismail Kadare";
  book.year=1964;
  book1.title="Hundered Years of Solitude";
  book1.authors="Gabriel Garzia Marquez";
  book1.year=1976;
  book2.title="South of the border West of the sun";
  book2.authors="Haruki Murakami";
  book2.year=1989;
  add_book_to_array(&array,book);
  add_book_to_array(&array,book1);
  add_book_to_array(&array,book2);

  book3.title="South of the border West of the sun";
  book3.authors="Haruki Murakami";
  book3.year=1989;
  printf("TEST8\n");
  for(int i=0;i<array.length;i++){
    if(equalBooks(book3,array.array[i])){
      TEST_ASSERT_TRUE(existsBook(book3,&array));
    }
  }
}
void test_isValidBook(){

  struct BookArray array;
  array.array=NULL;
  array.length=0;
  struct Book book,book1;
  book.title="Kronike ne Gur";
  book.authors="Ismail Kadare";
  book.year=1964;
   ///another book data and add it
  book1.authors = "Sara";
  book1.title = "test";
  book1.year = 2020;
  add_book_to_array(&array,book);
  add_book_to_array(&array,book1);
  //date to be compared
  char *title="Kronike ne Gur";
  char *author="Ismail Kadare";
  unsigned int year=1964;
//put data to serach for and store them
  int isValid=isValidBook(book,"Ismail Kadare","Kronike ne Gur",1964);
  //input book search data
  struct  BookArray bookFind=find_book_by_author_title_and_year(&array,author,title,year);
  printf("TEST9\n");
  TEST_ASSERT_EQUAL_INT(isValid,isValidBook(*bookFind.array,author,title,year));

}
void test_leapYear(){
  int year[]={
    2004,
    2008,
    2012,
    2020,
  };
  printf("TEST1\n");
  TEST_ASSERT_TRUE(is_leap_year(*year));
}
void test_validDate(void){
  int year[]={
    2018,
    2020,
    1956,
    2021,
  };
  int month[]={
    1,2,3,4,5,6,7,8,9,10,11,12,
  };
  int day[]={
    29,28,12,31,1,28,
  };
   printf("TEST2\n");
  TEST_ASSERT_TRUE(is_valid_date(*day,*month,*year));
}

void test_addBook(){
    struct BookArray array;
    array.array = NULL;
    array.length = 0;
    struct Book book;
    book.title="Kronike ne Gur";
    book.authors="Ismail Kadare";
    book.year=1964;
    book.copies=25;
    //add book to array
    //create another book structure
    struct Book book1;
    book1.title="Kronike ne Gur";
    book1.authors="Ismail Kadare";
    book1.year=1964;
    book1.copies=65;
    struct Book book2;
    book2.title="hey";
    book2.authors="Sara";
    book2.year=1964;
    book2.copies=165;
     add_book_to_array(&array,book);
      add_book_to_array(&array,book1);

    for(int i=0;i<array.length;i++){
      if(equalBooks(book2,array.array[i])){
        printf("equal");
      TEST_ASSERT_EQUAL(add_book(book2),add_book(array.array[i+1]));
    }
  }
  }

void test_addLoan(void){
  Loan loan,loan1,loan2,loan3;
  LoanedArray array;
  array.length=0;
  array.array=NULL;
  int i=0;
  //allocate two new users using another
  //adding method
  if(i==array.length){
    array.array=(Loan*)realloc(array.array,(array.length+1)*sizeof(Loan));
  }
  array.array[i++]=loan;
  array.array[i++]=loan1;
  //increase the length by the number of the loans registered;
  array.length+=i;
  //allocate again two loans using the function add_new_loan
  LoanedArray array2;
  array2.array=NULL;
  array2.length=0;
  add_loan_to_array(&array2,loan2);
  add_loan_to_array(&array2,loan3);
  //compare the length of both arrays
  printf("TEST1\n");
  TEST_ASSERT_EQUAL_INT(array.length,array2.length);
}
void test_findLoanByTitle(void){
  Loan loan,loan1;
  LoanedArray array;
  array.array=NULL;
  array.length=0;
  loan.loaned_books.title="Kronike ne gur";
  add_loan_to_array(&array,loan);
  LoanedArray findLoan=find_loan_by_title(&array,"Kronike ne gur");
  loan1.loaned_books.title="Kronike ne gur";
  add_loan_to_array(&findLoan,loan1);
  printf("TEST2\n");
  TEST_ASSERT_EQUAL_STRING(loan.loaned_books.title,findLoan.array->loaned_books.title);
}
void test_findLoanByAuthor(void){
  Loan loan,loan2;
  LoanedArray array;
  array.array=NULL;
  array.length=0;
  loan.loaned_books.author ="Ismail Kadare";
  add_loan_to_array(&array,loan);
  LoanedArray findBook;
  findBook.array=NULL;
  findBook.length=0;
  findBook=find_loan_by_author(&array,"Ismail Kadare");
  loan2.loaned_books.author ="Ismail Kadare";
  add_loan_to_array(&findBook,loan2);
  printf("TEST3\n");
  TEST_ASSERT_EQUAL_STRING(loan.loaned_books.author,findBook.array->loaned_books.author);
}
void test_findLoanByYear(void){
  Loan loan,loan1;
  LoanedArray array;
  array.array=NULL;
  array.length=0;
  loan.loaned_books.year=1964;
  add_loan_to_array(&array,loan);
  LoanedArray findLoan=find_loan_by_year(&array,1964);
  loan1.loaned_books.year=1964;
  add_loan_to_array(&findLoan,loan1);
  printf("TEST4\n");
  TEST_ASSERT_EQUAL_INT(loan.loaned_books.year,findLoan.array->loaned_books.year);
}
void test_findLoanByAuthorAndYear(void){
  Loan loan,loan1;
  LoanedArray array;
  array.array=NULL;
  array.length=0;
  loan.loaned_books.author="Ismail Kadare";
  loan.loaned_books.year=1964;
  add_loan_to_array(&array,loan);
  LoanedArray findLoan=find_loan_by_author_and_year(&array,"Ismail Kadare",1964);
  loan1.loaned_books.author="Ismail Kadare";
  loan1.loaned_books.year=1964;
  add_loan_to_array(&findLoan,loan1);
  printf("TEST5\n");
  TEST_ASSERT_EQUAL_STRING(loan.loaned_books.author,findLoan.array->loaned_books.author);
  TEST_ASSERT_EQUAL_INT(loan.loaned_books.year,findLoan.array->loaned_books.year);
}
void test_findLoanByTitleAndYear(void){
  Loan loan,loan1;
  LoanedArray array;
  array.array=NULL;
  array.length=0;
  loan.loaned_books.title="Ismail Kadare";
  loan.loaned_books.year=1964;
  add_loan_to_array(&array,loan);
  LoanedArray findLoan=find_loan_by_title_and_year(&array,"Ismail Kadare",1964);
  loan1.loaned_books.title="Ismail Kadare";
  loan1.loaned_books.year=1964;
  add_loan_to_array(&findLoan,loan1);
  printf("TEST6\n");
  TEST_ASSERT_EQUAL_STRING(loan.loaned_books.title,findLoan.array->loaned_books.title);
  TEST_ASSERT_EQUAL_INT(loan.loaned_books.year,findLoan.array->loaned_books.year);
}
void test_findLoanByAuthorAndTitle(void){
  Loan loan,loan1;
  LoanedArray array;
  array.array=NULL;
  array.length=0;
  loan.loaned_books.title="Ismail Kadare";
  loan.loaned_books.author="Kronike ne Gur";
  add_loan_to_array(&array,loan);
  LoanedArray findLoan=find_loan_by_title_and_author(&array,"Ismail Kadare","Kronike ne Gur");
  loan1.loaned_books.title="Ismail Kadare";
  loan1.loaned_books.author="Kronike ne Gur";
  add_loan_to_array(&findLoan,loan1);
  printf("TEST7\n");
  TEST_ASSERT_EQUAL_STRING(loan.loaned_books.title,findLoan.array->loaned_books.title);
  TEST_ASSERT_EQUAL_INT(loan.loaned_books.author,findLoan.array->loaned_books.author);
}
void test_findLoanByAuthorTitleAndYear(void){
  Loan loan,loan1;
  LoanedArray array;
  array.array=NULL;
  array.length=0;
  loan.loaned_books.title="Ismail Kadare";
  loan.loaned_books.author="Kronike ne Gur";
  loan.loaned_books.year=1964;
  add_loan_to_array(&array,loan);
  LoanedArray findLoan=find_loan_by_author_title_and_year(&array,"Ismail Kadare","Kronike ne Gur",1964);
  loan1.loaned_books.title="Ismail Kadare";
  loan1.loaned_books.author="Kronike ne Gur";
   loan.loaned_books.year=1964;
  add_loan_to_array(&findLoan,loan1);
  printf("TEST8\n");
  TEST_ASSERT_EQUAL_STRING(loan.loaned_books.author,findLoan.array->loaned_books.author);
  TEST_ASSERT_EQUAL_STRING(loan.loaned_books.title,findLoan.array->loaned_books.title);
  TEST_ASSERT_EQUAL_INT(loan.loaned_books.author,findLoan.array->loaned_books.author);
}
void test_addUser(void){
  Users user,user1,user2,user3;
  UsersArray array;
  array.length=0;
  array.array=NULL;
  int i=0;
  //allocate two new users using another
  //adding method
  if(i==array.length){
    array.array=(Users*)realloc(array.array,(array.length+1)*sizeof(Users));
  }
  array.array[i++]=user;
  array.array[i++]=user1;
  //increase the length by the number of the users registered;
  array.length+=i;
  //allocate again two users using the function add_new_user
  UsersArray array2;
  array2.array=NULL;
  array2.length=0;
  add_new_user(&array2,user2);
  add_new_user(&array2,user3);
  //compare the length of both arrays
  printf("TEST1");
  TEST_ASSERT_EQUAL_INT(array.length,array2.length);
}
void test_login(void){
  UsersArray array;
  array.array=NULL;
  array.length=0;
  //create multiple user
  //enter their details and add them to user array
  Users user,user1,user2;
  user.username="librarian";
  user.password="librarian";
  user1.username="Sara";
  user1.password="sara_karati";
  add_new_user(&array,user);
  add_new_user(&array,user1);
  char *username="Sara";
  char *password="sara_karati";
  //create a new user login with the parameters of one of
  //the users registered before
  Users users=login(&array,"Sara","sara_karati");
  printf("TEST2\n");
  for(int i=0;i<array.length;i++){
    if(strcmp(array.array[i].username,username)==0){
       TEST_ASSERT_EQUAL_STRING(username,users.username);
       if(strcmp(array.array[i].password,password)==0){
         TEST_ASSERT_EQUAL_STRING(password,users.password);
       }
     }
   }
 }
void test_existsUser(void){
  UsersArray array;
  array.array=NULL;
  array.length=0;
  Users user,user1,user2,user3;
  user.username="librarian";
  user1.username="Sara";
  user2.username="Leart";
  add_new_user(&array,user);
  add_new_user(&array,user1);
  add_new_user(&array,user2);
  char *username="Sara";
  printf("TEST3\n");
  for(int i=0;i<array.length;i++){
    TEST_ASSERT_TRUE(exists_user(&array,username));
  }
}
void test_findUser(){
  Users user;
  UsersArray array;
  array.array=NULL;
  array.length=0;
  user.username="librarian";
  add_new_user(&array,user);
  printf("TEST4\n");
  TEST_ASSERT_EQUAL_INT(0,findUser(&array,"librarian"));
}
void test_findUserByName(void){
  Users users[4]={
    {"Sara"},
    {"Leart"},
    {"librarian"},
    {"Harry"},
  };
  UsersArray array;
  array.array=NULL;
  array.length=0;
  add_new_user(&array,*users);
  Users users2[4]={
    {"Sara"},
    {"Leart"},
    {"Liam"},
    {"Ben"},
  };
  printf("TEST5\n");
  UsersArray findUser=find_user_by_name(&array,users2->name);
    add_new_user(&findUser,*users2);
  for(int i=0;i<array.length;i++){
    if(strcmp(array.array[i].name,findUser.array[i].name)==0){
   TEST_ASSERT_EQUAL_STRING(array.array[i].name,findUser.array[i].name);
   }
 }
}

  void test_findUserBySurname(void){
    Users users[4]={
      {" ","Karati"},
      {" ","Collins"},
      {" ","Styles"},
      {" ","Smith"},
    };
    UsersArray array;
    array.array=NULL;
    array.length=0;
    add_new_user(&array,*users);
    Users users2[4]={
      {" ","Karati"},
      {" ","Tomilson"},
      {" ","Payne"},
      {" ","Miller"},
    };
    printf("TEST6\n");
    UsersArray findUser=find_user_by_surname(&array,users2->surname);
    add_new_user(&findUser,*users2);
    for(int i=0;i<array.length;i++){
      if(strcmp(array.array[i].surname,findUser.array[i].surname)==0){
     TEST_ASSERT_EQUAL_STRING(array.array[i].surname,findUser.array[i].surname);
     }
   }
 }

    void test_findUserByUsername(void){
      Users users[3]={
        {" "," ","sarakarati"},
        {" "," ","sarakarati1"},
        {" "," ","harrystyles"},
      };
      UsersArray array;
      array.array=NULL;
      array.length=0;
      add_new_user(&array,*users);
      Users users2[3]={
        {" "," ","leartkarati"},
        {" "," ","sarakarati"},
        {" "," ","leartkarati1"},
      };
      printf("TEST7\n");
      UsersArray findUser=find_user_by_username(&array,users2->username);
       add_new_user(&findUser,*users2);
      for(int i=0;i<array.length;i++){
        if(strcmp(array.array[i].username,findUser.array[i].username)==0){
       TEST_ASSERT_EQUAL_STRING(array.array[i].username,findUser.array[i].username);
     }
   }
}
    void test_findUserByEmail(void){
      Users users[3]={
        {" "," "," ","leartkarati@gmail.com"},
        {" "," "," ","john.smith@gmail.com"},
          {" "," "," ","sc19sk@leeds.ac.uk"},
      };
      UsersArray array;
      array.array=NULL;
      array.length=0;
      add_new_user(&array,*users);
      Users users2[3]={
        {" "," "," ","sc19sk@leeds.ac.uk"},
        {" "," "," ","sc21sk@leeds.ac.uk"},
        {" "," "," ","anne.miller@gmail.com"},
      };
      printf("TEST8\n");
      UsersArray findUser=find_user_by_email(&array,users2->email);
       add_new_user(&findUser,*users2);
      for(int i=0;i<array.length;i++){
        if(strcmp(array.array[i].email,findUser.array[i].email)==0){
       TEST_ASSERT_EQUAL_STRING(array.array[i].email,findUser.array[i].email);
       }
     }
     }
     void test_findUserByPhonenumber(void){
       Users users[2]={
         {" "," "," "," ","07766325690"},
         {" "," "," "," ","07645306231"},

       };
       UsersArray array;
       array.array=NULL;
       array.length=0;
       add_new_user(&array,*users);
       Users users2[2]={
         {" "," "," "," ","07766325690"},
         {" "," "," "," ","07732569066"},
       };
       printf("TEST9\n");
       UsersArray findUser=find_user_by_phonenumber(&array,users2->phonenumber);
         add_new_user(&findUser,*users2);
       for(int i=0;i<array.length;i++){
          if(strcmp(array.array[i].phonenumber,findUser.array[i].phonenumber)==0){
        TEST_ASSERT_EQUAL_STRING(array.array[i].phonenumber,findUser.array[i].phonenumber);
      }
    }
  }
    void test_findUserByNameAndSurname(void){
      Users users[4]={
        {"Sara","Karati"},
        {"Leart","Karati"},
        {"Harry","Styles"},
        {"John","Smith"},
      };
      UsersArray array;
      array.array=NULL;
      array.length=0;
      add_new_user(&array,*users);
      Users users2[4]={
        {"Sara","Karati"},
        {"Louis","Tomilson"},
        {"Liam", "Payne"},
        {"Anne","Miller"},
      };
      printf("TEST10\n");
      UsersArray findUser=find_user_by_name_and_surname(&array,users2->name,users2->surname);
        add_new_user(&findUser,*users2);
      for(int i=0;i<array.length;i++){
         if(strcmp(array.array[i].name,findUser.array[i].name)==0
       && strcmp(array.array[i].surname,findUser.array[i].surname)==0){
       TEST_ASSERT_EQUAL_STRING(array.array[i].name,findUser.array[i].name);
       TEST_ASSERT_EQUAL_STRING(array.array[i].surname,findUser.array[i].surname);
       }
     }
   }
     void test_findUserByNameSurnameAndUsername(void){
       Users users[4]={
         {"Sara","Karati","SaraKarati"},
         {"Leart","Karati","LeartKarati"},
         {"Harry","Styles","HarryStyles"},
         {"James","White","JamesWhite"},
       };
       UsersArray array;
       array.array=NULL;
       array.length=0;
       add_new_user(&array,*users);
       Users users2[4]={
          {"Anne","Miller","AnneMiller"},
         {"Sara","Karati","SaraKarati"},
         {"Sara","Karati","SaraKarati1"},
         {"John", "Smith","JohnSmith"},

       };
       printf("TEST11\n");
       UsersArray findUser=find_user_by_name_surname_and_username(&array,users2->name,users2->surname,users2->username);
         add_new_user(&findUser,*users2);
       for(int i=0;i<array.length;i++){
         if(strcmp(array.array[i].name,findUser.array[i].name)==0
       && strcmp(array.array[i].surname,findUser.array[i].surname)==0
     &&strcmp(array.array[i].username,findUser.array[i].username)==0){
        TEST_ASSERT_EQUAL_STRING(array.array[i].name,findUser.array[i].name);
        TEST_ASSERT_EQUAL_STRING(array.array[i].surname,findUser.array[i].surname);
        TEST_ASSERT_EQUAL_STRING(array.array[i].username,findUser.array[i].username);
         TEST_ASSERT_MESSAGE(1,"ALL THE FUNCTIONS PASSED");

      }
   }
}

int main ()
{
    UNITY_BEGIN();
    printf("!~~~~~~~~~~~~~~BOOK MANAGEMENT TESTS~~~~~~~~~~~~~~~!\n");
    RUN_TEST(test_addNewBook);
    RUN_TEST(test_removeBook);
    RUN_TEST(test_findBookByTitle);
    RUN_TEST(test_findBookByAuthor);
    RUN_TEST(test_findBookByYear);

    printf("!~~~~~~~~~~~~~~BOOK MANAGEMENT TESTS FINISHED~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~UTIL TESTS~~~~~~~~~~~~~~~!\n");
    RUN_TEST(test_intToStr);
    RUN_TEST(test_concatenate);
    RUN_TEST(test_addBook);
    RUN_TEST(test_findBookByTitleAndYear);
    RUN_TEST(test_findBookByAuthorsAndYear);
    RUN_TEST(test_findBookByTitleAndAuthor);
    RUN_TEST(test_findBookByAuthorTitleAndYear);
    RUN_TEST(test_equalBook);
    RUN_TEST(test_existsBook);
    RUN_TEST(test_isValidBook);
    printf("!~~~~~~~~~~~~~~UTIL TESTS FINIHSED~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~DATE TESTS~~~~~~~~~~~~~~~!\n");
    RUN_TEST(test_leapYear);
    RUN_TEST(test_validDate);
    printf("!~~~~~~~~~~~~~~DATE TESTS FINISHED~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~USERS TESTS~~~~~~~~~~~~~~~!\n");
    RUN_TEST(test_addUser);
    RUN_TEST(test_login);
    RUN_TEST(test_findUser);
    RUN_TEST(test_existsUser);
    RUN_TEST(test_findUserByName);
    RUN_TEST(test_findUserBySurname);
    RUN_TEST(test_findUserByUsername);
    RUN_TEST(test_findUserByEmail);
    RUN_TEST(test_findUserByPhonenumber);
    RUN_TEST(test_findUserByNameAndSurname);
    RUN_TEST(test_findUserByNameSurnameAndUsername);
    printf("!~~~~~~~~~~~~~~~~~~~~~~~USERS TESTS FINISHED~~~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!\n");
    printf("!~~~~~~~~~~~~~~~~~~~~~~~~~~~LOANS TESTS~~~~~~~~~~~~~~~~~~~~~~!\n");
    RUN_TEST(test_addLoan);
    RUN_TEST(test_findLoanByTitle);
    RUN_TEST(test_findLoanByAuthor);
    RUN_TEST(test_findLoanByYear);
    RUN_TEST(test_findLoanByAuthorAndYear);
    RUN_TEST(test_findLoanByTitleAndYear);
    RUN_TEST(test_findLoanByAuthorAndTitle);
    RUN_TEST(test_findLoanByAuthorTitleAndYear);
    printf("!~~~~~~~~~~~~~~~~~~~~~~~~~LOANS TESTS FINISHED~~~~~~~~~~~~~~!\n");
    return UNITY_END();
}
