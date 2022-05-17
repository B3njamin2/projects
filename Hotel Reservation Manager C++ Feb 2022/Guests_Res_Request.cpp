#include "Guests_Res_Request.h"
#include <iostream>

Guests_Res_Request::Guests_Res_Request(const Guests_Res_Request& copy){
    guestPtr=new Guests(*copy.guestPtr);
    num_of_nights=copy.num_of_nights;
    id=copy.id;
}
Guests_Res_Request::Guests_Res_Request(const Guests& guests){
    
    //check if the check in date is before the check out date and that they are not in the March break Year
    if((guests.get_checkInPtr()->get_day()>=guests.get_checkOutPtr()->get_day())||(guests.get_checkInPtr()->get_year()!=guests.get_checkOutPtr()->get_year())){
        std::cout <<"\n\n!!Error: The CheckIn Date(";
        guests.get_checkInPtr()->print();
        std::cout<<") is ethier not before The CheckOut Date(";
        guests.get_checkOutPtr()->print();
        std::cout<<") or they are not in the same March break Year\n\n";
        exit(2);
    }
    // num of nights are calculated in the set_guests function
    // the id is also generated in the set_guests function
    set_guests(guests);
}
void Guests_Res_Request::set_guests(const Guests& guests){
    guestPtr=new Guests(guests);
    num_of_nights=guestPtr->get_checkOutPtr()->get_day()-guestPtr->get_checkInPtr()->get_day();
    static int temp{1};
    id=temp++;
}
const Guests* Guests_Res_Request::get_guestsPtr()const{
    return guestPtr;
}
int Guests_Res_Request::get_NumOfNights()const{
    return num_of_nights;
}
int Guests_Res_Request::get_ID()const{
    return id;
}
void Guests_Res_Request::print()const{
    std::cout<<"-------------------------------------------------------------------";
    std::cout<<"\nReservation ID: "<<id<<"  Number of Nights(Length of Stay): "<<num_of_nights<<std::endl;
    guestPtr->print();
    std::cout<<"-------------------------------------------------------------------\n";
}
Guests_Res_Request::~Guests_Res_Request(){
    delete guestPtr;
}
