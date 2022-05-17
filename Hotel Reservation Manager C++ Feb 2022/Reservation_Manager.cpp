#include "Reservation_Manager.h"
#include <iostream>
#include <iomanip>

Reservation_Manager::Reservation_Manager(){
    ReservationListPtr=new linkedlist;
}
int Reservation_Manager::reserve(const Guests_Res_Request* req){ 
    
    int Year = req->get_guestsPtr()->get_checkInPtr()->get_year();

    //Check if Year is valid
    if (year == 0){
        year=Year;
    }
    else if(year != Year ){
        std::cout<<"\n\n!!!!Error: The input reservation is not the same year as the other reservations on the list.\n"
        "Kindly make another Reservation_Manager to accommodate the reservations in different years\n"
        "\nThe year for this calander is: "<<year<<"\n";
        return -1;
    }

    int CheckInDay=req->get_guestsPtr()->get_checkInPtr()->get_day();
    int nights=req->get_NumOfNights();
    int id = req->get_ID();
    int roomNum=req->get_guestsPtr()->get_roomNum();

    //check if reservation day and room is available
    for(int i{CheckInDay}; i<CheckInDay+nights;i++){
        if(calander[i-1][roomNum-1]!=0){
            return -1;
        }
    }
    //set the reservation day and room on calander
    for(int i{CheckInDay}; i<CheckInDay+nights;i++){
        calander[i-1][roomNum-1]=id;
    }
    
    //Add the reservation to the list
    ReservationListPtr->append(req);
    return id;
}
void Reservation_Manager::cancel_res(int id){
    
    const Guests_Res_Request* cancel=ReservationListPtr->find(id);
    int CheckInDay=cancel->get_guestsPtr()->get_checkInPtr()->get_day();
    int nights=cancel->get_NumOfNights();
    int roomNum=cancel->get_guestsPtr()->get_roomNum();

    //access the calander and remove it from the reservation 
    for(int i{CheckInDay}; i<CheckInDay+nights;i++){
        calander[i-1][roomNum-1]=0;
    }
    //remove Guests_Res_Request object from list
    ReservationListPtr->deleteRequest(id);
}
const Guests_Res_Request* Reservation_Manager::get_resInfo(int id){
    return ReservationListPtr->find(id);
}
const int** Reservation_Manager::get_calenderPtr()const{
    //create dynamically allocated memory to copy the calander and return a const pointer
    const int** array = new const int*[max_no_of_nights];
    for( int i = 0; i < max_no_of_nights; ++i ){
    array[i]  = new int[ no_of_rooms ];
    }
    for(size_t i{0};i<max_no_of_nights;i++){
        array[i]=calander[i];
    }
    return array;
}
const linkedlist* Reservation_Manager::get_res_list()const{
    return ReservationListPtr;
}
int Reservation_Manager::get_maxNights()const{
    return max_no_of_nights;
}
int Reservation_Manager::get_numRooms()const{
    return no_of_rooms;
}
int Reservation_Manager::get_year()const{
    return year;
}
void Reservation_Manager::print_res_info(int id)const{
    ReservationListPtr->find(id)->print();
}
void Reservation_Manager::print()const{

    //print the 2d calander array which can adjust to the number of room and days
    std::cout<<"\n\n  (\\_/)"<<std::setw(101)<<"(\\_/)\n"<<"  ('x')"<<std::setw(100)<<" ('x')"<<" \n c(\")(\")"
    "---------------------------------------Hotel Reservation Table-------------------------------(\")(\")o"
    " \n\n       "<<"Maximum Number of Nights: "<<max_no_of_nights<<std::setw(33)<<"Reservation Year: "<<year;
    std::cout<<std::setw(36)<<"Number of Rooms: "<<no_of_rooms<<"\n\n       ";

    for(int i{0};i<no_of_rooms;i++){
        std::cout <<std::right<<std::setw(3)<<i+1<<"  ";
    }
    for (size_t i{0}; i < max_no_of_nights; ++i)
    {   
        std::cout << "\n      ";
        for(size_t i{0};i<no_of_rooms;i++)
        std::cout << "+----";
        std::cout <<"+\nMar "<<i+1<<" "<<std::left;
        for (int j = 0; j < no_of_rooms; ++j)
        {
            std::cout <<"| "<<std::setw(3)<< calander[i][j];
        }
        std::cout<<"|";
    }
    std::cout << "\n      ";
    for(size_t i{0};i<no_of_rooms;i++)
    std::cout << "+----";
    std::cout<<"+";

    //print list of guests information
    ReservationListPtr->print();
}
Reservation_Manager::~Reservation_Manager(){
    delete ReservationListPtr;
    // std::cout<<"\nReservation_Manager object memory deallocated\n";
}
