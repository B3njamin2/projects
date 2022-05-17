#pragma once
#include "Date.h"
#include <iostream>


class information{
    private:
        char firstName[30];
        char lastName[30];
        Date* birthDatePtr{NULL}; 
        information();
    public:
        // copy constructor
        information(const information&);

        //constructors
        information(const char[],const char[],const Date&);
        information(const Date&);  //This function will ask for the names in the terminal
        
        //setter & getter
        void set_firstName(const char[]);
        const char* get_firstName()const;

        void set_lastName(const char[]);
        const char* get_lastName()const;

        void set_birthDate(const Date&);
        const Date* get_birthDatePtr()const;
       
        //print function & destructor
        void print()const;
        ~information();
        friend class Guests;     
};
