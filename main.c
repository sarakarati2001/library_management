#include "book_management.h"
#include "interface.h"
#include "Users.h"
#include "date.h"
#include "util.h"
#include "loan.h"
#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>



void run(){

    booksLibrary.array = NULL;
    booksLibrary.length = 0;

    UsersArray users;
    users.array = NULL;
    users.length = 0;

    Users currentUser, user;
    UsersArray usersResult;
    usersResult.array = NULL;
    usersResult.length = 0;
    currentUser.username = NULL;
    LoanedArray loansResult,loans;
    users.array = NULL;
    users.length = 0;
    struct Book book;
    struct BookArray bookResult;
    Loan loan;
    char userChoice;
    bool back;
    int number, day, month, year,currentUserNumber;
    char* stringInput1, *stringInput2;
    char* booksLibrary_file = "libraryBooks.txt";
    char* usersLibrary_file = "libraryUsers.txt";
    FILE* readUsersFile = fopen(usersLibrary_file, "rb");
    FILE* readBooksFile = fopen(booksLibrary_file , "rb");
    //by deafult takes the librarian as the user of the system
    if(readUsersFile == NULL){
        Users admin;
        admin.name = "undefined";
        admin.surname = "undefined";
        admin.active = true;
        admin.loan.length = 0;
        admin.loan.array = NULL;
        admin.email = "undefined";
        admin.phonenumber = "undefined";
        admin.username = "librarian";
        admin.password = "librarian";
        add_new_user(&users, admin);
    }
    else{
        load_users(readUsersFile, &users);
        fclose(readUsersFile);
        // fclose(readBooksFile);

    }
    //read books file
    if(readBooksFile == NULL){
        struct Book book;
        book.title=NULL;
        book.authors=NULL;
        book.copies=0;
        book.year=0;
        printf("\n!**********\t-THE FILE COULD NOT BE READ-\t **********!\n");
    }
    else{
        load_books(readBooksFile);
    }


    while(1){
        if(currentUser.username == NULL){
            printf("\n\tUsername: ");
            currentUser.username = enterDetails();
            printf("\tPassword: ");
            currentUser.password = enterDetails();
            currentUser = login(&users,
                currentUser.username,
                currentUser.password);
                if(currentUser.username==NULL){
                    printf("\n\t\aInvalid data!\n");
                }
                else{
                    currentUserNumber = findUser(&users, currentUser.username);
                    printf("\n");
                }
            }
            //compare the usernames
            //in case the librarian logs in
            else if(strcmp(currentUser.username,"librarian") == 0
            &&strcmp(currentUser.password,"librarian")==0){
                displayAdminMenu();
                printf("\n\tEnter your option: ");
                scanf(" %c", &userChoice);
                switch(userChoice){
                    case '1':
                    back = false;
                    while(!back){
                        displayAdminUsersMenu();
                        printf("\n\tEnter your option: ");
                        scanf(" %c", &userChoice);
                        switch(userChoice){
                            case '1':
                            user = register_users();
                            int i = 2;
                            stringInput1= user.username;
                            while(exists_user(&users, stringInput1)){
                                stringInput1= concatenate(stringInput1, convertIntToString(i));
                                i++;
                            }
                            user.username = stringInput1;

                       printf("\n      ~~~~~~~~~~~~~~~~~~~~~~Your username is: ~~~~~~~~~~~~~~~~~\n\t\t\t\t\t%s", user.username );
                            add_new_user(&users, user);

                            break;

                            case '2':
                            printUserTable(&users);
                            printf("\tEnter user number: ");
                            scanf("%d", &number);
                            if(number < 1 || number > users.length){
                                printf("\n\tInvalid identifier!\n");
                            }
                            else{
                                back = false;
                                while(!back){
                                    displayAdminEditUsersMenu();
                                    printf("\n\tEnter your option: ");
                                    scanf(" %c", &userChoice);
                                    switch(userChoice){

                                        case '1':
                                        printf("\n\tEnter user's name: ");
                                        users.array[number - 1].name = enterDetails();
                                        break;

                                        case '2':
                                        printf("\n\tEnter user's surname: ");
                                        users.array[number - 1].surname = enterDetails();
                                        break;



                                        case '3':
                                        printf("\n\tEnter user's birthday (dd/mm/yyyy): ");
                                        scanf("%d/%d/%d", &day, &month, &year);

                                        if(is_valid_date(day,month,year))
                                        {
                                            users.array[number - 1].birthday.day = day;
                                            users.array[number - 1].birthday.month = month;
                                            users.array[number - 1].birthday.year = year;
                                        }
                                        else{
                                            printf("\n\tInvalid Date");
                                        }
                                        break;

                                        case '5':
                                        printf("\n\tEnter user's email: ");
                                        users.array[number - 1].email = enterDetails();
                                        break;

                                        case '6':
                                        printf("\n\tEnter user's phone number: ");
                                        users.array[number - 1].phonenumber = enterDetails();
                                        break;

                                        case '7':
                                        printf("\n\tEnter user's username: ");
                                        stringInput1= enterDetails();
                                        if(!exists_user(&users, stringInput1)){
                                            users.array[number - 1].username = enterDetails();
                                        }
                                        else{
                                            printf("\n\t\aInvalid username!\n");
                                        }
                                        break;

                                        case '8':
                                        printf("\n\tEnter user's password: ");
                                        users.array[number - 1].password = enterDetails();
                                        break;

                                        case '9':
                                        users.array[number - 1].active = !(users.array[number - 1].active);
                                        break;
                                        //users go back by typing either b or B
                                        case 'b':
                                        case 'B':
                                        back = true;
                                        break;

                                        default:
                                        printf("\n\tInvalid option!\a\n");

                                    }

                                }
                                back = false;
                            }
                            break;

                            case '3':
                            printUserTable(&users);
                            break;

                            case '4':

                            back = false;
                            while(!back){
                                displayAdminSearchUsersMenu();
                                printf("\n\tEnter your option: ");
                                scanf(" %c", &userChoice);
                                switch(userChoice){
                                    case '1':
                                    printf("\n\tEnter User's Name: ");
                                    stringInput1= enterDetails();
                                    usersResult = find_user_by_name(&users, stringInput1);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }
                                    break;

                                    case '2':
                                    printf("\n\tEnter User's Surname: ");
                                    stringInput1= enterDetails();
                                    usersResult = find_user_by_surname(&users, stringInput1);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }
                                    break;
                                    case '3':
                                    printf("\n\tEnter User's Email: ");
                                    usersResult = find_user_by_email(&users, stringInput1);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }


                                    break;
                                    case '4':
                                    printf("\n\tEnter User's Username: ");
                                    stringInput1 = enterDetails();
                                    usersResult = find_user_by_username(&users, stringInput1);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }
                                    break;

                                    case '5':
                                    printf("\n\tEnter User's Phone Number: ");
                                    stringInput1= enterDetails();
                                    usersResult = find_user_by_phonenumber(&users, stringInput1);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }
                                    break;
                                    case '6':
                                    printf("\n\tEnter User's Name: ");
                                    stringInput1 = enterDetails();
                                    printf("\tEnter User's Surname: ");
                                    stringInput2 = enterDetails();
                                    usersResult = find_user_by_name_and_surname(&users, stringInput1, stringInput2);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }
                                    break;


                                    case '7':
                                    printf("\n\tEnter User's Name: ");
                                    stringInput1  = enterDetails();
                                    printf("\n\tEnter User's Surname: ");
                                    stringInput2 = enterDetails();
                                    printf("\n\tEnter User's Username: ");
                                    char *stringInput3  = enterDetails();
                                    usersResult = find_user_by_name_surname_and_username(&users, stringInput1,stringInput2,stringInput3);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }
                                    break;

                                    case '8':
                                    printf("\n\tEnter User's Loaned Book Title: ");
                                    stringInput1= enterDetails();
                                    printf("\n\tEnter User's Loaned Book Author: ");
                                    stringInput2 = enterDetails();
                                    printf("\n\t Enter User#s Loaned Book Year: ");
                                    scanf("%d",&year);
                                    usersResult = find_user_by_loan(&users,stringInput1,stringInput2,year);
                                    if(usersResult.length == 0){
                                        printf("\n\t0 results!\n");
                                    }
                                    else{
                                        printUserTable(&usersResult);
                                        printf("\tEnter user number: ");
                                        scanf("%d", &number);
                                        if(number < 1 || number > usersResult.length){
                                            printf("\n\tInvalid identifier!\n");
                                        }
                                        else{
                                            viewUser(&users.array[number - 1]);
                                        }
                                    }

                                    break;

                                    case 'b':
                                    case 'B':
                                    back = true;
                                    break;

                                    default:
                                    printf("\n\tInvalid option!\a\n");
                                }
                                back = false;
                                break;

                                case 'b':
                                case 'B':
                                back = true;
                                break;

                                default:
                                printf("\n\tInvalid option!\a\n");

                            }
                        }
                    }

                    break;

                    case '2':
                    back = false;
                    while(!back){
                        displayAdminBooksMenu();
                        printf("\n\tEnter your option: ");
                        scanf(" %c", &userChoice);
                        switch(userChoice){
                            case '1':
                            book = new_book_details();
                            if(existsBook(book, &booksLibrary)){
                                 //in case book exists add number of copies for that book
                                  add_book(book);
                                }
                                //in case the book doesnt exist add it to the library
                                add_book_to_array(&booksLibrary, book);
                                break;

                              case '2':
                              printBookTable(&booksLibrary);
                              printf("\tEnter book number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > booksLibrary.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              number=remove_book(book);
                              break;

                            case '3':
                            printBookTable(&booksLibrary);
                            printf("\tEnter book number: ");
                            scanf("%d", &number);
                            if(number < 1 || number > booksLibrary.length){
                                printf("\n\tInvalid identifier!\n");
                            }
                            else{
                                back = false;
                                while(!back){
                                    displayAdminEditBooksMenu();
                                    printf("\n\tEnter your option: ");
                                    scanf(" %c", &userChoice);
                                    switch(userChoice){
                                        case '1':
                                        printf("\n\tEnter Book's Title': ");
                                        booksLibrary.array[number - 1].title = enterDetails();

                                        break;
                                        case '2':
                                        printf("\n\tEnter Book's Author': ");
                                        booksLibrary.array[number - 1].authors = enterDetails();


                                        break;
                                        case '3':
                                        printf("\n\tEnter Book's Year': ");
                                        scanf("%d",&year);
                                        break;
                                        case '4':
                                        printf("\n\tEnter Book's Copies': ");
                                        scanf("%d",&booksLibrary.array[number-1].copies);
                                        break;

                                        case 'b':
                                        case 'B':
                                        back = true;
                                        break;

                                        default:
                                        printf("\n\tInvalid option!\a\n");

                                    }
                                }
                                back = false;
                            }
                            break;

                            case '4':
                            printBookTable(&booksLibrary);
                            break;

                            case '5':
                            displayAdminSearchBooksMenu();
                            printf("\n\tEnter your option: ");
                            scanf(" %c", &userChoice);
                            switch(userChoice){
                                case '1':
                                printf("\n\tEnter Book's Title: ");
                                stringInput1 = enterDetails();
                                bookResult = find_book_by_title(book.title);
                                if(usersResult.length == 0){
                                    printf("\n\t0 results!\n");
                                }
                                else{
                                    printBookTable(&bookResult);
                                    printf("\tEnter user number: ");
                                    scanf("%d", &number);
                                    if(number < 1 || number > bookResult.length){
                                        printf("\n\tInvalid identifier!\n");
                                    }
                                    else{
                                        viewBook(&booksLibrary.array[number - 1]);
                                    }
                                }
                                break;

                                case '2':
                                printf("\n\tEnter Book's Author: ");
                                stringInput1 = enterDetails();

                                bookResult = find_book_by_author(book.authors);
                                if(bookResult.length == 0){
                                    printf("\n\t0 results!\n");
                                }
                                else{
                                    printBookTable(&bookResult);
                                    printf("\tEnter user number: ");
                                    scanf("%d", &number);
                                    if(number < 1 || number > bookResult.length){
                                        printf("\n\tInvalid identifier!\n");
                                    }
                                    else{
                                        viewBook(&booksLibrary.array[number - 1]);
                                    }
                                }

                                break;

                                case '3':
                                printf("\n\tEnter Book's Year: ");
                                scanf("%d",&year);
                                bookResult = find_book_by_year(book.year);
                                if(bookResult.length == 0){
                                    printf("\n\t0 results!\n");
                                }
                                else{
                                    printBookTable(&bookResult);
                                    printf("\tEnter user number: ");
                                    scanf("%d", &number);
                                    if(number < 1 || number > bookResult.length){
                                        printf("\n\tInvalid identifier!\n");
                                    }
                                    else{
                                        viewBook(&booksLibrary.array[number - 1]);
                                    }
                                }

                                break;

                                case '4':
                                printf("\n\tEnter Book's Author: ");
                                stringInput1 = enterDetails();
                                printf("\tEnter Book's Title: ");
                                stringInput2 = enterDetails();
                                bookResult = find_book_by_author_and_title(&booksLibrary, stringInput1,stringInput2);
                                if(bookResult.length == 0){
                                    printf("\n\t0 results!\n");
                                }
                                else{
                                    printBookTable(&bookResult);
                                    printf("\tEnter user number: ");
                                    scanf("%d", &number);
                                    if(number < 1 || number > bookResult.length){
                                        printf("\n\tInvalid identifier!\n");
                                    }
                                    else{
                                        viewBook(&booksLibrary.array[number - 1]);
                                    }
                                }

                                break;

                                case '5':
                                printf("\n\tEnter Book's Title: ");
                                stringInput1 = enterDetails();
                                printf("\tEnter Book's Year: ");
                                scanf("%d",&year);
                                bookResult = find_book_by_title_and_year(&booksLibrary, stringInput1, year);
                                if(bookResult.length == 0){
                                    printf("\n\t0 results!\n");
                                }
                                else{
                                    printBookTable(&bookResult);
                                    printf("\tEnter user number: ");
                                    scanf("%d", &number);
                                    if(number < 1 || number > bookResult.length){
                                        printf("\n\tInvalid identifier!\n");
                                    }
                                    else{
                                        viewBook(&booksLibrary.array[number - 1]);
                                    }
                                }

                                break;
                                case '6':
                                printf("\n\tEnter Book's Author: ");
                                stringInput1 = enterDetails();
                                printf("\tEnter Book's Year: ");
                                scanf("%d",&year);
                                bookResult = find_book_by_author_and_year(&booksLibrary, stringInput1, year);
                                if(bookResult.length == 0){
                                    printf("\n\t0 results!\n");
                                }
                                else{
                                    printBookTable(&bookResult);
                                    printf("\tEnter user number: ");
                                    scanf("%d", &number);
                                    if(number < 1 || number > bookResult.length){
                                        printf("\n\tInvalid identifier!\n");
                                    }
                                    else{
                                        viewBook(&booksLibrary.array[number - 1]);
                                    }
                                }
                                break;
                                case '7':
                                printf("\n\tEnter Book's Author: ");
                                stringInput1 = enterDetails();
                                printf("\n\tEnter Book's Title: ");
                                stringInput2=enterDetails();
                                printf("\n\tEnter Book's  Year:  ");
                                scanf("%d",&year);
                                bookResult = find_book_by_author_title_and_year(&booksLibrary,stringInput1,stringInput2,year);
                                if(usersResult.length == 0){
                                    printf("\n\t0 results!\n");
                                }
                                else{
                                    printBookTable(&bookResult);
                                    printf("\tEnter user number: ");
                                    scanf("%d", &number);
                                    if(number < 1 || number > bookResult.length){
                                        printf("\n\tInvalid identifier!\n");
                                    }
                                    else{
                                        viewBook(&booksLibrary.array[number - 1]);
                                    }
                                }


                                case 'b':
                                case 'B':
                                back = true;
                                break;

                                default:
                                printf("\n\tInvalid option!\a\n");
                            }
                        }
                        back = false;
                        break;




                        case 'L':
                        case 'l':
                        currentUser.username = NULL;
                        back = true;
                        break;

                        case 'Q':
                        case 'q':
                        exit(1);
                        break;

                        default:
                        printf("\n\tInvalid option!\a\n\n");

                    }
                }
            }

            else{
                displayUserMenu1();
                printf("\n\tEnter your option: ");
                scanf(" %c", &userChoice);
                switch(userChoice){
                    case '1':
                    back = false;
                    while(!back){
                        displayUserMyProfileMenu();
                        printf("\n\tEnter your option: ");
                        scanf(" %c", &userChoice);
                        switch(userChoice){
                            case '1':
                            viewUser(&currentUser);
                            break;

                            case '2':
                                back = false;
                                while(!back){
                                 displayUserEditMyProfileMenu();
                                    printf("\n\tEnter your option: ");
                                    scanf(" %c", &userChoice);


                                    switch(userChoice){
                                        case '1':
                                        printf("Enter Your Name:");
                                        users.array[number-1].name=enterDetails();
                                        currentUser.name=users.array[number-1].name;
                                        break;

                                        case '2':
                                        printf("Enter Your Surname:");
                                        users.array[number-1].surname=enterDetails();
                                        currentUser.surname=users.array[number-1].surname;
                                        break;

                                        case '3':
                                        printf("Change Your Password:");
                                        users.array[number-1].password=enterDetails();
                                        currentUser.password=users.array[number-1].password;

                                        break;

                                        case '4':
                                        printf("Change Your Phone Number:");
                                        users.array[number-1].phonenumber=enterDetails();
                                        currentUser.phonenumber=users.array[number-1].phonenumber;

                                        break;

                                        case '5':
                                        printf("Change Your Email:");
                                        users.array[number-1].email=enterDetails();
                                        currentUser.email=users.array[number-1].email;

                                        break;

                                        case 'b':
                                        case 'B':
                                        back = true;

                                        default:
                                        printf("\n\tInvalid option!\a\n");
                                    }

                            }
                            back = false;
                            break;

                            case 'b':
                            case 'B':
                            back = true;
                            break;

                            default:
                            printf("\n\tInvalid option!\a\n");
                        }
                    }
                    back=false;
                    break;

                    case '2':
                    back = false;
                        while(!back){
                          displayUserMyLoansMenu();
                          printf("\n\tEnter your option: ");
                          scanf(" %c", &userChoice);
                        switch(userChoice){
                         case '1':
                            printf("\n\t Enter Book's Title: ");
                            stringInput1=enterDetails();
                            printf("\n\t Enter Book's Author: ");
                            stringInput2=enterDetails();
                            printf("\n\t Enter Book's Year: ");
                            scanf("%d",&year);
                          //if the book data is valid
                          if(isValidBook(book,stringInput1,stringInput2,year)!=-1){
                              loan_book(&user,loan);
                          }else{
                             printf("  Wrong Input");
                          }
                          break;
                          case '2':
                          printf("\n\t Enter Book's Title: ");
                          stringInput1=enterDetails();
                          printf("\n\t Enter Book's Author: ");
                          stringInput2=enterDetails();
                          printf("\n\t Enter Book's Year: ");
                          scanf("%d",&year);
                          if(equalLoan(loan.loaned_books,loansResult.array->loaned_books)){
                              return_loan(&user,loan);
                              }
                          break;
                      case '3':
                        printLoansTable(&currentUser);
                        printf("\tEnter loan number: ");
                        scanf("%d", &number);
                        if(number < 1 || number > user.loan.length){
                            printf("\n\tInvalid identifier!\n");
                        }
                        else{
                            viewLoan(&currentUser.loan.array[number - 1]);
                        }
                      break;
                      case '4':
                      displayUserSearchLoansMenu();
                      printf("\n\tEnter your option: ");
                      scanf(" %c", &userChoice);
                      switch(userChoice){
                          case '1':
                          printf("\n\tEnter Book's Title: ");
                          stringInput1 = enterDetails();
                         user=find_loan_by_title(&currentUser,stringInput1);
                          if(user.loan.length == 0){
                              printf("\n\t0 results!\n");
                          }
                          else{
                              printLoansTable(&user);
                              printf("\tEnter user number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > user.loan.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              else{
                                  viewLoan(&currentUser.loan.array[number - 1]);
                              }
                          }
                          break;

                          case '2':
                          printf("\n\tEnter Book's Author: ");
                          stringInput1 = enterDetails();
                          user.loan=find_loan_by_author(&currentUser,stringInput1);
                          if(user.loan.length == 0){
                              printf("\n\t0 results!\n");
                          }
                          else{
                              printLoansTable(&user);
                              printf("\tEnter user number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > user.loan.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              else{
                                  viewLoan(&currentUser.loan.array[number - 1]);
                              }
                          }

                          break;

                          case '3':
                          printf("\n\tEnter Book's Year: ");
                          scanf("%d",&year);
                         user=find_loan_by_year(&currentUser,year);
                          if(user.loan.length == 0){
                              printf("\n\t0 results!\n");
                          }
                          else{
                              printLoansTable(&user);
                              printf("\tEnter user number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > user.loan.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              else{
                                  viewLoan(&currentUser.loan.array[number - 1]);
                              }
                          }

                          break;

                          case '4':
                          printf("\n\tEnter Book's Title: ");
                          stringInput1 = enterDetails();
                          printf("\tEnter Book's Author: ");
                          stringInput2 = enterDetails();
                         user=find_loan_by_title_and_author(&currentUser,stringInput1,stringInput2);
                          if(user.loan.length == 0){
                              printf("\n\t0 results!\n");
                          }
                          else{
                              printLoansTable(&user);
                              printf("\tEnter user number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > user.loan.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              else{
                                  viewLoan(&currentUser.loan.array[number - 1]);
                              }
                          }
                          break;

                          case '5':
                          printf("\n\tEnter Book's Title: ");
                          stringInput1 = enterDetails();
                          printf("\tEnter Book's Year: ");
                          scanf("%d",&year);
                         user=find_loan_by_title_and_year(&currentUser,stringInput1,year);
                          if(user.loan.length == 0){
                              printf("\n\t0 results!\n");
                          }
                          else{
                              printLoansTable(&user);
                              printf("\tEnter user number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > user.loan.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              else{
                                  viewLoan(&currentUser.loan.array[number - 1]);
                              }
                          }

                          break;
                          case '6':
                          printf("\n\tEnter Book's Author: ");
                          stringInput1 = enterDetails();
                          printf("\tEnter Book's Year: ");
                          scanf("%d",&year);
                          if(user.loan.length == 0){
                             user=find_loan_by_author_and_year(&currentUser,stringInput1,year);
                              printf("\n\t0 results!\n");
                          }
                          else{
                              printLoansTable(&user);
                              printf("\tEnter user number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > user.loan.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              else{
                                  viewLoan(&currentUser.loan.array[number - 1]);
                              }
                          }
                          break;
                          case '7':
                          printf("\n\tEnter Book's Author: ");
                          stringInput1 = enterDetails();
                          printf("\n\tEnter Book's Title: ");
                          stringInput2=enterDetails();
                          printf("\n\tEnter Book's  Year:  ");
                          scanf("%d",&year);
                          user=find_loan_by_author_title_and_year(&currentUser,stringInput1,stringInput2,year);
                          if(user.loan.length == 0){
                              printf("\n\t0 results!\n");
                          }
                          else{
                              printLoansTable(&user);
                              printf("\tEnter user number: ");
                              scanf("%d", &number);
                              if(number < 1 || number > user.loan.length){
                                  printf("\n\tInvalid identifier!\n");
                              }
                              else{
                                  viewLoan(&currentUser.loan.array[number - 1]);
                              }
                          }
                          case 'b':
                          case 'B':
                          back = true;
                          break;

                          default:
                          printf("\n\tInvalid option!\a\n");
                      }

                      back = false;

                      break;

                      case 'b':
                      case 'B':
                      back = true;
                      break;

                      default:
                      printf("\n\tInvalid option!\a\n");

                  }
              }
              back = false;
              break;

              case 'L':
              case 'l':
              currentUser.username = NULL;
              back = true;
              break;

              case 'Q':
              case 'q':
              exit(1);
              break;

              default:
              printf("\n\tInvalid option!\a\n\n");

          }
      }
  }


}
