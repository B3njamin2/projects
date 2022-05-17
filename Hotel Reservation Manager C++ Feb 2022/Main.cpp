#include <iostream>
#include "Reservation_Manager.h"
//Benjamin Cheng Chuan Tan 40210666 assingment 1

// Refer to .h files for all the functions
// All get functions for an object returns a constant object pointer that is not mutable 
// These pointers do not create a copy of the data stored in the class, it only points to it.
// The date format is (DD/MM/YYYY)
// All the dates will be checked for validity
/* An error message will be displayed if the check in date is not before the check out date
 * If the dates are not during the march break
 * If the dates are not in the same march break year
*/ 

//for demonstration purposes the Reservation_manger is initialized in global to avoid it beind destroyed in the created scope below
Reservation_Manager* Manager= new Reservation_Manager;
int main(){
    {
    //-------------------------------------------------------------
    //Reservation 1 (creating a reservation)
    //-------------------------------------------------------------
    Date date(23,8,1994);
    information info("Dr Theo","Amedda",date);
    date.setdate(7,3,1978);
    information info1("Ellinor","Chase",date);
    date.setdate(19,5,1988);
    information info2("Jenifer","Foster",date);
    date.setdate(1,5,1988);
    information info3("Zeo","Drake",date);

    Date checkin(1,3,2021);
    Date checkout(5,3,2021);

    information arr[4]={info,info1,info2,info3};
    //guests(checkin, checkout, room number, array, array size)
    Guests guests(checkin,checkout,5,arr,4);
    Guests_Res_Request* Request=new Guests_Res_Request(guests);

    std::cout<<"\n\nBooking Guests_Res_Request 1: "<<Manager->reserve(Request);

    //reserving the same request twice will fail due to overlapping reservation dates
    std::cout<<"\n\nBooking Guests_Res_Request 1 twice: "<<Manager->reserve(Request)<<std::endl;

    //-------------------------------------------------------------
    //Reservation 2 (using setter and getters to make new request)
    //-------------------------------------------------------------
    info.set_birthDate(date);
    info.set_firstName("Tonya");
    info.set_lastName("Tifft");

    guests.set_infoArr(info);
    
    guests.set_checkIn(Date(5,3,2021));
    guests.set_checkOut(Date(8,3,2021));
  
    Request->set_guests(guests);
    Manager->reserve(Request);
    delete Request;

    //-------------------------------------------------------------
    //Reservation 3 (create a request to be deleted)
    //-------------------------------------------------------------
    Guests_Res_Request* Request2=new Guests_Res_Request(Guests(checkin,checkout,8,information("N/A","N/A",Date(1,1,1))));
    
    Manager->reserve(Request2);
    Manager->cancel_res(Request2->get_ID());
    
    //-------------------------------------------------------------
    //Reservation 4 (filler)
    //-------------------------------------------------------------
    guests.set_res_dates(Date(1,3,2021),Date(8,3,2021));
    guests.set_roomNum(20);
    guests.set_infoArr(information("Benjamin","Tan",Date(4,1,2001)));
    Request2->set_guests(guests);
    Manager->reserve(Request2);
    delete Request2;
    }// every thing in this scope will be deleted this verifies that the copy constructor was done properly

    Manager->print();// the Manager print function will cause a chain reaction of print functions from all the classes
    
    //-------------------------------------------------------------
    //-------------------------------------------------------------
    std::cout<<"\nTesting Manager functions\n\n";
    
    Manager->print_res_info(4);// find reservation id 4 and print it

    const int** calander= Manager->get_calenderPtr();// using the get function to get the calander array

    //printing then deleting the calander array using the pointer inizialized above
    for (size_t i{0};i<Manager->get_maxNights();i++){
        for(size_t j{0};j<Manager->get_numRooms();j++){
            std::cout<<calander[i][j]<<" ";
        }
        std::cout<<std::endl;
        delete[] calander[i];
    }
    delete[] calander;
    
    delete Manager;
    return 0;

}