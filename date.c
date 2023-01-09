#include "date.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//function checks if the year is a leap year or not
//it returns true if the year is a
bool is_leap_year(int year){
  if((year%4==0 || year%100!=0) || year%400==0){
    return true;
  }
  return false;
}
//the function checks if the user inputs a valid date
bool is_valid_date(int day,int month,int year){
  //year cannot be bigger than the year we are now
  if(year < 1929 || year > 2021 ){
    return false;
  }else{
  if(day < 1 && day > 31 && month < 1 && month > 12){
    return false;
  }
  if(month==2){
    if(is_leap_year(year)){
      if(day>29){
        return false;
      }
    }else{
      if(day > 28){
        return true;
      }
    }
  }
  if(month==4 || month == 6 || month == 9 || month == 11){
    if(day > 30){
      return false;
    }
  }
  return true;
}
}
