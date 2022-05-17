
#include "Information.h"
#include <iostream>
#include <cstring>

information::information():firstName("N/A"),lastName("N/A"),birthDatePtr(nullptr){}
information::information(const information& copy){
    strcpy(firstName,copy.firstName);
    strcpy(lastName,copy.lastName);
    birthDatePtr = new Date(*copy.birthDatePtr);
}
information::information(const char FirstName[30],const char LastName[30],const Date& bday){
    strcpy(firstName,FirstName);
    strcpy(lastName,LastName);
    birthDatePtr=new Date(bday);
}
information::information(const Date& bday){
    std::cout << "\nWhat is the first name?: ";
    std::cin.getline(firstName,30); 
        
    std::cout<< "What is the last name?:  ";
    std::cin.getline(lastName,30); 
    std::cout <<std::endl;

    birthDatePtr = new Date(bday);
}
void information::set_firstName(const char Name[30]){
    strcpy(firstName, Name);
}
const char* information::get_firstName()const{
    return firstName;
}
void information::set_lastName(const char Name[30]){
    strcpy(lastName, Name);
}
const char* information::get_lastName()const{
    return lastName;
}
void information::set_birthDate(const Date& bday){
    *birthDatePtr=bday;
}
const Date* information::get_birthDatePtr()const{
    return &*birthDatePtr;
}
void information::print()const{
    std::cout<<"\nFirst Name: "<<firstName<<"\nLast Name:  "<<lastName<<"\nBirth Date: ";
    birthDatePtr->print();
    std::cout <<std::endl;
}
information::~information(){
    delete birthDatePtr;
}
