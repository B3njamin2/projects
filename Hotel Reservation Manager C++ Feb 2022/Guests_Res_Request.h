#pragma once
#include "Guests.h"

//In this class there is no get function for ID and num_of_nights
//The Id will be auto generated and the num_of_nights will be calculated with the checkIn and checkOut data from the Guests object 
class Guests_Res_Request{
    private:
        Guests* guestPtr{nullptr};
        int num_of_nights{0};
        int id{0};

    public:
        // copy constructor
        Guests_Res_Request(const Guests_Res_Request&);

        //constructor
        Guests_Res_Request(const Guests&);
        
        //setter & getter
        void set_guests(const Guests&);
        const Guests* get_guestsPtr()const;
        int get_NumOfNights()const;
        int get_ID()const;

        //print function & destructor
        void print()const;
        ~Guests_Res_Request();    
};
