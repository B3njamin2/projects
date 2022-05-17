#pragma once
#include "Information.h"

class Guests{
    private:
        Date* checkInPtr{nullptr};
        Date* checkOutPtr{nullptr};
        information infoArr[4];
        int roomNum{0};
        size_t arr_size{0};
    public:
        // copy constructor
        Guests(const Guests&);

        //constructors
        Guests(const Date&,const Date&,int,const information[],size_t);
        Guests(const Date&,const Date&,int,const information&); //accepts one info object instead of array 

        //setter & getter
        void set_infoArr(const information[],size_t);
        const information* get_infoArr()const;
        void set_res_dates(const Date&,const Date&);//check in and check out can be set together or independently
        void set_checkIn(const Date&);
        const Date* get_checkInPtr()const;
        void set_checkOut(const Date&);
        const Date* get_checkOutPtr()const;
        void set_infoArr(const information&);
        void set_roomNum(int);
        int get_roomNum()const;

        //print function & destructor
        void print()const;
        ~Guests();
};
