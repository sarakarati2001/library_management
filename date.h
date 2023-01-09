#ifndef DATE_GUARD__H
#define DATE_GUARD__H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct Dates{
  int day;
  int month;
  int year;
}Date;
bool is_leap_year(int year);
//the function checks if the user inputs a valid date
bool is_valid_date(int day,int month,int year);
#endif
