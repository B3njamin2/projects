#pragma once
#include "Res_linkedList.h"
#include <iostream>


class Reservation_Manager{
    private:
        static const int max_no_of_nights{7};
        static const int no_of_rooms{20};
        linkedlist* ReservationListPtr{nullptr};
        int calander[max_no_of_nights][no_of_rooms]={0};
        int year{0};
    public:
        //defualt constructor
        Reservation_Manager();

        
        int reserve(const Guests_Res_Request*); //reserve reservation
        void cancel_res(int); // cancel reservation

        //getters
        const linkedlist* get_res_list()const;  //get reservation list
        const Guests_Res_Request* get_resInfo(int); //the reservation of id entered
        const int** get_calenderPtr()const; //get 2d array of reservation
        
        int get_maxNights()const;
        int get_numRooms()const;
        int get_year()const;

        
        //print function & destructor
        void print_res_info(int)const;//print the guest info of id entered
        void print()const;// prints everything
        ~Reservation_Manager();
};
