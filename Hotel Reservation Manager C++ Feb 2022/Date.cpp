#include "Date.h"
#include <iostream>

Date::Date(int Day, int Month, int Year){
   setdate(Day, Month, Year);
}
void Date::setdate(int Day, int Month, int Year){
    if ((((Month<1)||(Month>12))||(Year<1))||((Day<1)||(Day>31))){
        std::cout <<"\n\nError!!!:Invalid date detected for date object initialization\n\n";
        exit(0);
    }
    else{
        month=Month;
        day=Day;
        year=Year;
    }
}
int Date::get_day()const{
    return day;
}
int Date::get_month()const{
    return month;
}
int Date::get_year()const{
    return year;
}
void Date::print()const{
    std::cout<< day<<"/"<<month<<"/"<<year;
}
Date::~Date(){
    // std::cout<<"\nDate object memory deallocated\n";
}