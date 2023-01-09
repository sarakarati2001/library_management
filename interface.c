
#include <stdio.h>
#include "interface.h"

void displayUserMenu1(){
    printf("\n\t #      Options\n");
    printf("\n\t[1] -   My Profile\n");
    printf("\n\t[2] -   My Loans\n");
    printf("\n\t[L] -   Logout\n");
    printf("\n\t[Q] -   Quit\n");
}


void displayUserMyProfileMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Display\n");
    printf("\n\t[2] - Edit\n");
    printf("\n\t[B] - Back\n");
}

void displayUserMyLoansMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Add New Loan\n");
    printf("\n\t[2] - Return Loan\n");
    printf("\n\t[3] - Print Loans\n");
    printf("\n\t[4] - Search Loaned Book\n");
    printf("\n\t[B] - Back\n");
}
void displayUserSearchLoansMenu(){
  printf("\n\t #    Options\n");
  printf("\n\t[1] - Search By Title\n");
  printf("\n\t[2] - Search By Authors\n");
  printf("\n\t[3] - Search By Year\n");
  printf("\n\t[4] - Search By Title And Authors\n");
  printf("\n\t[5] - Search By Title And Year\n");
  printf("\n\t[6] - Search By Authors And Year\n");
  printf("\n\t[7] - Search By Title, Authors And Year\n");
  printf("\n\t[B] - Back\n");

}

void displayUserEditMyProfileMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Edit Name\n");
    printf("\n\t[2] - Edit Surname\n");
    printf("\n\t[3] - Change Password\n");
    printf("\n\t[4] - Change Phone Number\n");
    printf("\n\t[5] - Change Email\n");
    printf("\n\t[B] - Back\n");
}
void displayUsersSearchBooksMenu(){
    printf("\n\t #    Option\n");
    printf("\n\t[1] - Search By Title\n");
    printf("\n\t[2] - Search By Authors\n");
    printf("\n\t[3] - Search By Year\n");
    printf("\n\t[4] - Search By Title And Authors\n");
    printf("\n\t[5] - Search By Title And Year\n");
    printf("\n\t[6] - Search By Authors And Year\n");
    printf("\n\t[7] - Search By Title, Authors And Year\n");
    printf("\n\t[B] - Back\n");
}

void displayAdminMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Users\n");
    printf("\n\t[2] - Books\n");
    printf("\n\t[L] - Logout\n");
    printf("\n\t[Q] - Quit\n");
}

void displayAdminUsersMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Add New User\n");
    printf("\n\t[2] - Edit User\n");
    printf("\n\t[3] - List Users\n");
    printf("\n\t[4] - Search User\n");
    printf("\n\t[B] - Back\n");
}

void displayAdminEditUsersMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Edit User Name\n");
    printf("\n\t[2] - Edit User Surname\n");
    printf("\n\t[5] - Edit Email\n");
    printf("\n\t[6] - Edit Phone Number\n");
    printf("\n\t[7] - Edit User Username\n");
    printf("\n\t[8] - Edit User Password\n");
    printf("\n\t[9] - Edit User Active\n");
    printf("\n\t[B] - Back\n");
}

void displayAdminSearchUsersMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Search By Name\n");
    printf("\n\t[2] - Search By Surname\n");
    printf("\n\t[3] - Search By Username\n");
    printf("\n\t[4] - Search By Email\n");
    printf("\n\t[5] - Search By Phone Number\n");
    printf("\n\t[6] - Search By Name And Surname\n");
    printf("\n\t[7] - Search By Name Surname And Username\n");
    printf("\n\t[B] - Back\n");
}

void displayAdminBooksMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Add New Book\n");
    printf("\n\t[2] - Remove Book\n");
    printf("\n\t[3] - Edit Book Data\n");
    printf("\n\t[4] - List Books\n");
    printf("\n\t[5] - Search Books\n");
    printf("\n\t[B] - Back\n");
}

void displayAdminEditBooksMenu(){
    printf("\n\t #    Options\n");
    printf("\n\t[1] - Edit Book Title\n");
    printf("\n\t[2] - Edit Book Author\n");
    printf("\n\t[3] - Edit Book Year\n");
    printf("\n\t[4] - Edit Book Copies\n");
    printf("\n\t[B] - Back\n");
}

void displayAdminSearchBooksMenu(){
    printf("\n\t #    Option\n");
    printf("\n\t[1] - Search By Title\n");
    printf("\n\t[2] - Search By Authors\n");
    printf("\n\t[3] - Search By Year\n");
    printf("\n\t[4] - Search By Title And Authors\n");
    printf("\n\t[5] - Search By Title And Year\n");
    printf("\n\t[6] - Search By Authors And Year\n");
    printf("\n\t[7] - Search By Title, Authors And Year\n");
    printf("\n\t[B] - Back\n");
}
