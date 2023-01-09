
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <math.h>
#include "util.h"
#include "book_management.h"

 //since c language doesn't allow us to enter long sentences or strings
 //we create a method which will allow us to enter long strings.
 char *enterDetails(){
   char character;
   char *string = (char*)malloc(sizeof(char)*2048);
   do{
     scanf("%c",&character);
   }while(character=='\n' || character=='\t' || character==' ');
   int i=1;
   string[0]=character;
   while(i < 2048 && character!='\n'){
        scanf("%c",&character);
          string[i]=character;
          i++;
   }
   string[strlen(string)-1]='\0';
   return string;
 }
char *convertIntToString(int number){
//log10 +1 is used to count the number of digits,  but we add 2 to log10
//because strings terminate with '\0'
  int length = (int)log10(number) + 2;
  //allocate a new string;
  char *string=(char*)malloc(length*sizeof(char));
  if(string==NULL){
    return NULL;
  }
  int i;
  //iterate through the string
  for(i=1;i<length;i++){
    //start from the beggining of the string and store the numbers
    //in the string
    string[length-1-i] = number%10 + '0';
    //go through each digit of the number
    number/=10;
  }
  //terminate the string
  string[length]='\0';
  return string;
}

 //the function concatenates two strings
 char* concatenate(char *string1,char *string2){
   int length = strlen(string1)+strlen(string2);
   char *concatenate_string=(char*)malloc(sizeof(char)*length);
   int i,j,counter=0;
   for(i=0;i<strlen(string1);i++){
     concatenate_string[i]=string1[i];
   }
   for(j=strlen(string1);j<length;j++){
     concatenate_string[j]=string2[counter++];
   }

   concatenate_string[length]='\0';
   return concatenate_string;
 }
 //the function converts integers to strings
 //the function is needed when we give usernames to users
 // char *convertIntToString();
 //the users requests a book
 void printBookTable(struct BookArray *bookArray){
   int counter;
   if(bookArray->length==0){
     printf("No data registered\n");
   }else{
     printf("Number\t\t\t\t\t Title\t\t\t\t\t Author(s)\t\t\t\t\t\t\t Year\t\t\t\t\t Copies\n");
   for(counter=1;counter <= bookArray->length;counter++){
     printf("%d %s %s %d %d",counter,bookArray->array[counter-1].title,
     bookArray->array [counter-1].authors,
     bookArray->array [counter-1].year,
     bookArray->array[counter-1].copies);
 }
}
 printf("\n");
}
 struct Book new_book_details(){
   printf("   ***************************************************************");
   struct Book book;
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter the book's title:~~~~~~~~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   book.title= enterDetails();
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter the book's author(s):~~~~~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   book.authors= enterDetails();
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter the book's year:~~~~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   scanf("%d",&book.year);
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter the number of copies:~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   scanf("%d",&book.copies);
   printf("   ***************************************************************\n");
   return book;
 }
 void viewBook(struct Book *book){
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Title:%s~~~~~~~~~~~~~~~~~~~~~~\n", book->title);
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Author:%s~~~~~~~~~~~~~~~~~~~~~\n", book->authors);
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Year:%d~~~~~~~~~~~~~~~~~~~~~~\n", book->year);
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Copies:%d~~~~~~~~~~~~~~~~~~~~~\n", book->copies);
    printf("\n\n");
 }
 void add_book_to_array(struct BookArray *bookArray,struct Book book){
   struct Book *arrayBook=(struct Book*)malloc(sizeof(struct Book)*(bookArray->length+1));
   if(arrayBook == NULL){
       printf("Could not allocate the array!!");
       return;
   }else{
       int i=0;
       while(i<bookArray->length){
           arrayBook[i]=bookArray->array[i];

           i++;
       }
       arrayBook[i]=book;
   }
   if(bookArray->length!=0){
       free(bookArray->array);
   }

   bookArray->array=arrayBook;
   bookArray->length++;

 }
 struct BookArray find_book_by_author_and_title (struct BookArray *bookArray,const char *author,const char *title){
 	struct BookArray newBooksLibrary;
 	newBooksLibrary.length = 0;
 	newBooksLibrary.array = NULL;
 	int j;

 	//for all the books in library
 	for(j=0;j<bookArray->length;j++){
 		//compare the title with the title of the books in library
 		if(strcasecmp(author,bookArray->array[j].authors)==0
  &&strcasecmp(title,bookArray->array[j].title)){
 			//if the titles are the same
 			//reallocate the found book in newBooksLibrary;
       add_book_to_array(&newBooksLibrary,bookArray->array[j]);
	   }
 	}
 	return newBooksLibrary;
 }
 struct BookArray find_book_by_author_and_year (struct BookArray *bookArray,const char *author,unsigned int year){
   struct BookArray newBooksLibrary;
   newBooksLibrary.length = 0;
   newBooksLibrary.array = NULL;
   int j;
   //for all the books in library
   for(j=0;j<bookArray->length;j++){
     //compare the title with the title of the books in library
     if(strcasecmp(author,bookArray->array[j].authors)==0
   && bookArray->array[j].year==year){
       //if the titles are the same
       //reallocate the found book in newBooksLibrary;
      add_book_to_array(&newBooksLibrary,bookArray->array[j]);
     }
   }
   return newBooksLibrary;

 }
 struct BookArray find_book_by_title_and_year (struct BookArray *bookArray,const char *title,unsigned int year){
   struct BookArray newBooksLibrary;
   newBooksLibrary.length = 0;
   newBooksLibrary.array = NULL;
   int j;
   //for all the books in library
   for(j=0;j<bookArray->length;j++){
     //compare the title with the title of the books in library
     if(strcasecmp(title,bookArray->array[j].title)==0
   && bookArray->array[j].year==year){
       //if the titles are the same
       //reallocate the found book in newBooksLibrary;
      add_book_to_array(&newBooksLibrary,bookArray->array[j]);
     }
   }
   return newBooksLibrary;
 }
 struct BookArray find_book_by_author_title_and_year (struct BookArray *bookArray,const char *author,const char *title,unsigned int year){
   struct BookArray newBooksLibrary;
   newBooksLibrary.length = 0;
   newBooksLibrary.array = NULL;
   int j;
   //for all the books in library
   for(j=0;j<bookArray->length;j++){
     //compare the title with the title of the books in library
     if(strcasecmp(author,bookArray->array[j].authors)==0
     &&strcasecmp(title,bookArray->array[j].title)==0
   && bookArray->array[j].year==year){
       //if the titles are the same
       //reallocate the found book in newBooksLibrary;
       add_book_to_array(&newBooksLibrary,bookArray->array[j]);
     }
   }
   return newBooksLibrary;
 }
bool equalBooks(struct Book book1,struct Book book2){
    if(strcasecmp(book1.title, book2.title) == 0 &&
       strcasecmp(book1.authors, book2.authors) == 0 &&
       book1.year == book2.year){
        return true;
    }
	return false;
}
bool existsBook(struct Book book, struct BookArray *books)
{
	int i;
	for(i = 0; i < books->length;i++)
	{
		 if(equalBooks(book, books->array[i])){
            return true;
		 }
	}
	return false;
}
int isValidBook(struct Book books,char *title,char *author,int year){
    if(strcasecmp(title,books.title)==0
     &&strcasecmp(author,books.authors)==0
   && books.year==year && books.copies>0){
      return 0;
  }
return -1;
}
int findBook(struct Book book,struct BookArray *books){

  for(int j=0;j<books->length;j++){
  //compare the title with the title of the books in library
    if(strcasecmp(book.authors,books->array[j].authors)==0
    &&strcasecmp(book.title,books->array[j].title)==0
    && books->array[j].year==book.year){
      return j;
      }
    }
  return -1;
}
