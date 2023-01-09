#include "Users.h"
#include "util.h"
#include "date.h"
#include "loan.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>

//the function returns 0 in case of success
//or error code otherwise
int store_users(FILE *file,UsersArray *usersArray){
  file=fopen("libraryUsers.txt","wb");
  if(file==NULL){
    printf("!!!!ERROR THE FILE IS NULL");
  }
  int i=0;
  while(i<usersArray->length){
    fwrite(&usersArray->array,sizeof(Users),1,file);
  i++;
}
  return 0;
}
//the function returns 0 in case of success or error code otherwise
int load_users(FILE *file,UsersArray *usersArray){
  while(true){
    Users user;
    if(fread(&usersArray->array,sizeof(Users),1,file)!=1){
      printf("could not read the file");
      break;
    }
    add_new_user(usersArray,user);
  }
  return 0;
}
void add_new_user(UsersArray *usersArray,Users user){
  //create a new array of Users
  //we increase the size by one since we are adding a new user
  Users * result =
     (Users*)malloc(sizeof(Users) * (usersArray->length + 1));
 if(result == NULL){
     printf("\nError while reallocating memory to add user!");
     return;
   }else{
     int i = 0;
     while(i < usersArray->length){
         result[i] = usersArray->array[i];
         i++;
     }
     result[i] = user;
   }
   if(usersArray->length != 0){
     free(usersArray->array);
   }
   usersArray->array = result;
usersArray->length++;
}
Users register_users(){
   Users user;
   printf("   ***************************************************************");
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter your name:~~~~~~~~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   user.name = enterDetails();
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter your surname:~~~~~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   user.surname = enterDetails();
   user.username = concatenate(user.name,user.surname);

   printf("\n \n     ~~~~~~~~~~~~~~~~~~~~~~Enter your password:~~~~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   user.password = enterDetails();
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter your phonenumber:~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   user.phonenumber = enterDetails();
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter your email:~~~~~~~~~~~~~~~~~~\n");
   printf("\t\t\t\t\t");
   user.email = enterDetails();
   printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Enter your birthday(dd/mm/yyyy):~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\t\t");
   scanf("%2d/%2d/%4d",&user.birthday.day,&user.birthday.month, &user.birthday.year);
   printf("   ***************************************************************\n");
   user.loan.array=NULL;
   user.loan.length=0;
    return user;
}
//we return the user who will login in case the username inputted
//by the user exists or a null username if it does not exists
Users login(UsersArray *libraryUsers,char *username,char *password){
    //first we check if the username exists
    //then we check for the password
    //because the username can exist and the inputted password may be wrong
    int j = 0;
  while(j < libraryUsers->length)
  {
      if(strcmp(libraryUsers->array[j].username, username) == 0)
      {
          if(strcmp(libraryUsers->array[j].password, password) == 0){
              return libraryUsers->array[j];
          }
          break;
      }
      j++;
  }
  Users result;
  result.username = NULL;
  return result;
}
 bool exists_user(UsersArray *libraryUsers,char *username){
   //iterate through users of library array
  for(int i=0;i<libraryUsers->length;i++){
     if(strcmp(username,libraryUsers->array[i].username)==0){
       return true;
     }
   }
   return false;
 }
 UsersArray find_user_by_name(UsersArray *libraryUsers, char *name){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(strcasecmp(name,libraryUsers->array[i].name)==0){
      add_new_user(&arrayUsers,libraryUsers->array[i]);
  }
   }
   return arrayUsers;
 }
 UsersArray find_user_by_surname(UsersArray *libraryUsers, char *surname){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(strcasecmp(surname,libraryUsers->array[i].surname)==0){
      add_new_user(&arrayUsers,libraryUsers->array[i]);

}
   }
   return arrayUsers;
 }

 UsersArray find_user_by_username(UsersArray *libraryUsers, char *username){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(strcmp(username,libraryUsers->array[i].username)==0){
       add_new_user(&arrayUsers,libraryUsers->array[i]);
   }
 }
 return arrayUsers;
}
 UsersArray find_user_by_email(UsersArray *libraryUsers, char *email){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(strcmp(email,libraryUsers->array[i].email)==0){
       add_new_user(&arrayUsers,libraryUsers->array[i]);
   }
   }
       return arrayUsers;
 }


 UsersArray find_user_by_phonenumber(UsersArray *libraryUsers, char *phonenumber){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(strcmp(phonenumber,libraryUsers->array[i].phonenumber)==0){
          add_new_user(&arrayUsers,libraryUsers->array[i]);
      }
   }
   return arrayUsers;
 }

 UsersArray find_user_by_birthday       (UsersArray *libraryUsers,Date date){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(libraryUsers->array[i].birthday.day==date.day &&libraryUsers->array[i].birthday.month==date.month
     &&libraryUsers->array[i].birthday.year==date.year){
       add_new_user(&arrayUsers,libraryUsers->array[i]);
   }
   }
   return arrayUsers;
 }
 UsersArray find_user_by_loan           (UsersArray *libraryUsers, char* title, char* authors, int year){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(strcasecmp(title,libraryUsers->array[i].loan.array->loaned_books.title)==0 &&
    strcasecmp(authors,libraryUsers->array[i].loan.array->loaned_books.author)==0
    &&libraryUsers->array[i].loan.array->loaned_books.year==year){
        add_new_user(&arrayUsers,libraryUsers->array[i]);
    }
   }
   return arrayUsers;

 }
 UsersArray find_user_by_name_and_surname(UsersArray *libraryUsers,char* name,char *surname){
   UsersArray arrayUsers;
   arrayUsers.length=0;
   arrayUsers.array=NULL;
   for(int i=0;i<libraryUsers->length;i++){
     if(strcasecmp(name,libraryUsers->array[i].name)==0 && strcasecmp(surname,libraryUsers->array[i].surname)==0){
       add_new_user(&arrayUsers,libraryUsers->array[i]);
   }
   }
   return arrayUsers;
 }
 UsersArray find_user_by_name_surname_and_username(UsersArray *libraryUsers,char *name,char *surname,char *username){
    UsersArray arrayUsers;
    arrayUsers.length=0;
    arrayUsers.array=NULL;
    for(int i=0;i<libraryUsers->length;i++){
      if(strcasecmp(name,libraryUsers->array[i].name)==0 && strcasecmp(surname,libraryUsers->array[i].surname)==0
      &&strcmp(username,libraryUsers->array[i].username)==0){
        add_new_user(&arrayUsers,libraryUsers->array[i]);
      }
  }
    return arrayUsers;
}
 void printUserTable(UsersArray *usersArray){
   int counter;
   if(usersArray->length==0){
     printf("No data registered\n");
   }else{
     printf("Name\t\t\t  Surname\t\t\tUsername\t\t\tEmail\t\t\t Phonenumber\n");
   for(counter=1;counter <= usersArray->length;counter++){
     printf("%d %s %s %s %s %s\n",counter,usersArray->array[counter-1].name,
     usersArray->array [counter-1].surname,
     usersArray->array [counter-1].username,
     usersArray->array [counter-1].email,
     usersArray->array [counter-1].phonenumber);
 }
}
 printf("\n");
}
void viewLoan(Loan *loans){
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Title:%s~~~~~~~~~~~~~~~~~~~~~~\n",      loans->loaned_books.title);
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Author:%s~~~~~~~~~~~~~~~~~~~~~\n",     loans->loaned_books.author);
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Year:%d~~~~~~~~~~~~~~~~~~~~~~\n",  loans->loaned_books.year);
  printf("\n\n");
}
void viewUser(Users *users){
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Name:%s~~~~~~~~~~~~~~~~~~~~~~\n",      users->name);
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Surname:%s~~~~~~~~~~~~~~~~~~~~~\n",     users->surname);
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Username:%s~~~~~~~~~~~~~~~~~~~~~~\n",  users->username);
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Email:%s~~~~~~~~~~~~~~~~~~~~~\n",       users->email);
  printf("\n\t~~~~~~~~~~~~~~~~~~~~~~Phonenumber:%s~~~~~~~~~~~~~~~~~~~~~\n", users->phonenumber);
    printf("\n\t~~~~~~~~~~~~~~~~~~~~Birthday:%2d/%2d/%4d~~~~~~~~~~~~~~~~~~~~~\n", users->birthday.day,users->birthday.month,users->birthday.year);
    printf("\n\tLoans:             %d", users->loan.length);
       printf("\n\n");
       int i;
       for(i = 0; i < users->loan.length; i++){
           printf("\n\tLoan %d\n", i + 1);
           viewLoan(&users->loan.array[i]);
       }
  printf("\n\n");
}
void loan_book(Users *users,Loan loan){
  Loan*loanedArray=(Loan*)malloc(sizeof(Loan)*(users->loan.length+1));
  if(loanedArray==NULL){
    printf("\t!********* Array could not be allocated! **********!\n");
    return;
  }else{
      int i=0;
  while(i<users->loan.length){
    loanedArray[i]=users->loan.array[i];
    i++;
  }
    loanedArray[i]=loan;
  }
  if(users->loan.length!=0){
    free(users->loan.array);
  }
  users->loan.array=loanedArray;
  users->loan.length++;
}

void printLoansTable(Users *users){
  int counter;
  if(users->loan.length==0){
    printf("No data registered");
  }else{
    printf("Number\t\tTitle\t\t\t\t\t Author(s)\t\t\t\t\t\t\t Year\n");
  for(counter=1;counter <=users->loan.length;counter++){
    printf("%d %s %s %d",counter,users->loan.array[counter-1].loaned_books.title,
  users->loan.array[counter-1].loaned_books.author,
    users->loan.array[counter-1].loaned_books.year);
}
}
printf("\n");
}
Users find_loan_by_author_title_and_year(Users *usersLoan,char *author,char *title,unsigned int year){
  Users arrayLoans;
  arrayLoans.loan.length=0;
  arrayLoans.loan.array=NULL;
  for(int i=0;i<usersLoan->loan.length;i++){
    if(strcasecmp(title,usersLoan->loan.array[i].loaned_books.title)==0
    &&strcasecmp(author,usersLoan->loan.array[i].loaned_books.author)==0
  &&usersLoan->loan.array[i].loaned_books.year==year){
      add_loan_to_array(&arrayLoans.loan,usersLoan->loan.array[i]);
    }
  }
  return arrayLoans;
}
Users find_loan_by_title(Users *usersLoan,char *title){
  Users arrayLoans;
  arrayLoans.loan.length=0;
  arrayLoans.loan.array=NULL;
  for(int i=0;i<usersLoan->loan.length;i++){
    if(strcasecmp(title,usersLoan->loan.array[i].loaned_books.title)==0){
      add_loan_to_array(&arrayLoans.loan,usersLoan->loan.array[i]);
    }
  }
  return arrayLoans;
}
Users find_loan_by_author(Users *usersLoan,char *author){
  Users arrayLoans;
  arrayLoans.loan.length=0;
  arrayLoans.loan.array=NULL;
  for(int i=0;i<usersLoan->loan.length;i++){
    if(strcasecmp(author,usersLoan->loan.array[i].loaned_books.author)==0){
      add_loan_to_array(&arrayLoans.loan,usersLoan->loan.array[i]);
    }
  }
  return arrayLoans;
}
Users find_loan_by_year(Users *usersLoan,unsigned int year){
  Users arrayLoans;
  arrayLoans.loan.length=0;
  arrayLoans.loan.array=NULL;
  for(int i=0;i<usersLoan->loan.length;i++){
    if(usersLoan->loan.array[i].loaned_books.year ==  year){
      add_loan_to_array(&arrayLoans.loan,usersLoan->loan.array[i]);
    }
  }
  return arrayLoans;
}
Users find_loan_by_title_and_author(Users *usersLoan,char *title,char *author){
  Users arrayLoans;
  arrayLoans.loan.length=0;
  arrayLoans.loan.array=NULL;

  for(int i=0;i<usersLoan->loan.length;i++){
    if(strcasecmp(author,usersLoan->loan.array[i].loaned_books.author)==0
  &&strcasecmp(title,usersLoan->loan.array[i].loaned_books.title)==0){
      add_loan_to_array(&arrayLoans.loan,usersLoan->loan.array[i]);
    }
  }
  return arrayLoans;
}
Users find_loan_by_title_and_year(Users *usersLoan,char *title,unsigned int year){
  Users arrayLoans;
  arrayLoans.loan.length=0;
  arrayLoans.loan.array=NULL;
  for(int i=0;i<usersLoan->loan.length;i++){
    if(strcasecmp(title,usersLoan->loan.array[i].loaned_books.title)==0
  &&usersLoan->loan.array[i].loaned_books.year==year){

      add_loan_to_array(&arrayLoans.loan,usersLoan->loan.array[i]);

    }
  }
  return arrayLoans;

}
Users find_loan_by_author_and_year(Users *usersLoan,char *author,unsigned int year){
  Users arrayLoans;
  arrayLoans.loan.length=0;
  arrayLoans.loan.array=NULL;
  for(int i=0;i<usersLoan->loan.length;i++){
    if(strcasecmp(author,usersLoan->loan.array[i].loaned_books.author)==0
  &&usersLoan->loan.array[i].loaned_books.year==year){
      add_loan_to_array(&arrayLoans.loan,usersLoan->loan.array[i]);
    }
  }
  return arrayLoans;
}


int findUser(UsersArray* users, char* username){
    int i;
    for(i = 0; i < users->length; i++)
    {
        if(strcasecmp(users->array[i].username, username) == 0){
            return i;
        }
    }
    return -1;
}
void return_loan(Users  *users,Loan loan){}
