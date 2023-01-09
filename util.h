#ifndef UTIL_H__GUARD
#define UTIL_H__GUARD



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "book_management.h"


//this file contains helping functions for all the files.



 //since c language doesn't allow us to enter long sentences or strings
 //we create a method which will allow us to enter long strings.
 char* enterDetails();
 //the function concatenates two strings
 char* concatenate(char *string1,char *string2);
 //the function converts integers to strings
 //the function is needed when we give usernames to users
 char *convertIntToString();
 void printBookTable(struct BookArray *usersArray);
 //the users requests a book
 struct Book new_book_details();
 void viewBook(struct Book *book);
 void add_book_to_array(struct BookArray *bookArray, struct Book book);
struct BookArray find_book_by_author_and_title (struct BookArray *bookArray,const char *author,const char *title);
struct BookArray find_book_by_author_and_year (struct BookArray *bookArray,const char *author,unsigned int year);
struct BookArray find_book_by_title_and_year (struct BookArray *bookArray,const char *title,unsigned int year);
struct BookArray find_book_by_author_title_and_year (struct BookArray *bookArray,const char *author,const char *title,unsigned int year);
bool equalBooks(struct Book book1,struct Book book2);
bool existsBook(struct Book book, struct BookArray *books);
int isValidBook(struct Book books,char *title,char *author,int year);
int findBook(struct Book book,struct BookArray *books);

#endif
