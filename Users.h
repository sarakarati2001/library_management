#ifndef USERS_GUARD__H
#define USERS_GUARD__H
#include "loan.h"
#include "date.h"
#include "util.h"
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct UsersofLibrary {
	char *name; //user's name
	char *surname; //user's surname
	char *username;
	char *email;//user's email
	char *phonenumber ;//user's phonenumber
	char *password;//user's password

	LoanedArray loan;//the users' loaned books
	//since the phonenumbers are made of 11 digits
	//char data type can be used
	Date birthday; //user's birthday
	bool active;
}Users;
typedef struct UsersofLibraryArray {
	Users *array; // pointer to array of struct Users.
	unsigned int length; // number of elements in the struct Users
}UsersArray;
//we write to a file using this functions
int store_users(FILE *file,UsersArray *usersArray);
//we read from a file
//each time we use the program changes are saved in a file
int load_users(FILE *file,UsersArray *usersArray);
//the function works like a form
//it asks users to give their details
Users register_users();
//the functions enables user to login
//it checks if the username and the password for that username exists
Users login(UsersArray *libraryUsers,char *username,char *password);
//the function adds a new user in the array of users
void add_new_user(UsersArray *usersArray,Users user);
//the function checks if the user with a certain username exists
bool exists_user                   (UsersArray *libraryUsers,char *username);
//the function is used to find the user by their name
UsersArray find_user_by_name       (UsersArray *libraryUsers, char *name);
//the function is used to find the user by their surname
UsersArray find_user_by_surname    (UsersArray *libraryUsers, char *surname);
//the function is used to find use by their username
UsersArray find_user_by_username    (UsersArray *libraryUsers, char *username);
//the function is used to find user by his email address
UsersArray find_user_by_email      (UsersArray *libraryUsers, char *email);
//the function finds user by their phonenumber
UsersArray find_user_by_phonenumber(UsersArray *libraryUsers, char *phonenumber);
//Users find_user_by_loan( UsersArray libraryUsers,Loan loan);
//Users find_user_by_birthday( UsersArray libraryUsers,Date date);
UsersArray find_user_by_name_and_surname(UsersArray *libraryUsers,char* name,char *surname);
UsersArray find_user_by_name_surname_and_username(UsersArray *libraryUsers,char *name,char *surname,char *username);
UsersArray find_user_by_birthday       (UsersArray *libraryUsers,Date date);
UsersArray find_user_by_loan           (UsersArray *libraryUsers, char* title, char* authors, int year);
void loan_book(Users *users,Loan loan);
Users find_loan_by_author_title_and_year(Users *usersLoan,char *author,char *title,unsigned int year);
Users find_loan_by_title(Users *users,char *title);
Users find_loan_by_author(Users *users,char *author);
Users find_loan_by_year(Users *users,unsigned int year);
Users find_loan_by_title_and_author(Users *users,char *title,char *author);
Users find_loan_by_title_and_year(Users *users,char *title,unsigned int year);
Users find_loan_by_author_and_year(Users *users,char *author,unsigned int year);
//the function works like a database
//it stores all the details of the registered users in a table
void printUserTable();
void viewUser(Users *users);
void printLoansTable(Users *users);
void viewLoan(Loan *loans);
int findUser(UsersArray* users, char* username);
void return_loan(Users  *users,Loan loan);
#endif
