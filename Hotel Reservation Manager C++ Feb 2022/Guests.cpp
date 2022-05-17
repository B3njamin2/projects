#include "Guests.h"
#include <iostream>
#include <cstring>

Guests::Guests(const Guests& copy){
    checkInPtr=new Date(*copy.checkInPtr);
    checkOutPtr=new Date(*copy.checkOutPtr);

    // copies the array of information
    for (size_t i{0};i<copy.arr_size;i++){
        strcpy(infoArr[i].firstName,copy.infoArr[i].firstName);
        strcpy(infoArr[i].lastName,copy.infoArr[i].lastName);
        infoArr[i].birthDatePtr=new Date(*(copy.infoArr[i].birthDatePtr));
    }
        
    roomNum=copy.roomNum;
    arr_size=copy.arr_size;
}
Guests::Guests(const Date& CheckIn,const Date& CheckOut, int RoomNum,const information info[],size_t size){
    set_infoArr(info,size);
    set_res_dates(CheckIn,CheckOut);
    set_roomNum(RoomNum);
}
Guests::Guests(const Date& CheckIn,const  Date& CheckOut,int RoomNum,const information& info){
    set_infoArr(info);
    set_res_dates(CheckIn,CheckOut);
    set_roomNum(RoomNum);
}
void Guests::set_infoArr(const information info[],size_t size){
    if(size>4){std::cout<<"\n\n!Error: Invalid Information Class Array size\n\n";exit(2);}
    
    if (arr_size>size)
    {
        for(size_t i{size};i<arr_size;i++){
            infoArr[i]=information();
        }
    }
    // copies the array
    for(size_t i{0};i<size;i++){
        strcpy(infoArr[i].firstName,info[i].firstName);
        strcpy(infoArr[i].lastName,info[i].lastName);
        infoArr[i].birthDatePtr=new Date(*(info[i].birthDatePtr));
    }
    arr_size=size;
    
}
void Guests::set_infoArr(const information& info){
    for(size_t i{1};i<arr_size;i++){
        infoArr[i]=information();
    }
    strcpy(infoArr[0].firstName,info.firstName);
    strcpy(infoArr[0].lastName,info.lastName);
    infoArr[0].birthDatePtr=new Date(*(info.birthDatePtr));
    arr_size=1;        
}
const information* Guests::get_infoArr()const{
    return infoArr;
}
void Guests::set_res_dates(const Date& CheckIn,const Date& CheckOut){
    set_checkIn(CheckIn);
    set_checkOut(CheckOut);
}
void Guests::set_checkIn(const Date& CheckIn){
    if((CheckIn.get_day()>8)||(CheckIn.get_month()!=3)){
        std::cout<<"\n\n!!!Error: CheckIn Date(";
        CheckIn.print();
        std::cout<<") is not during the march break\n\n";
        exit(2);
    }
    checkInPtr=new Date(CheckIn);
}
const Date* Guests::get_checkInPtr()const{
    return checkInPtr;
}
void Guests::set_checkOut(const Date& CheckOut){
    if((CheckOut.get_day()>8)||(CheckOut.get_month()!=3)){
            std::cout<<"\n\n!!!Error: CheckOut Date(";
            CheckOut.print();
            std::cout<<") is not during the march break\n\n";
            exit(2);
        }
    checkOutPtr=new Date(CheckOut);
}
const Date* Guests::get_checkOutPtr()const{
    return checkOutPtr;
}
void Guests::set_roomNum(int RoomNum){
    if((RoomNum<1)||(RoomNum>20)){std::cout<<"\nError:Invalid RoomNum input";exit(2);}
        else
            roomNum=RoomNum;
}
int Guests::get_roomNum()const{
    return roomNum;
}
void Guests::print()const{
    std::cout <<"\nCheck In Date: ";
    checkInPtr->print();
    std::cout <<"  Check Out Date: ";
    checkOutPtr->print();
    std::cout <<"  Room Number: "<<roomNum<<std::endl;
    
    for (size_t i{0};i<arr_size;i++){
        infoArr[i].print();
    }
}
Guests::~Guests(){
    delete checkInPtr;
    delete checkOutPtr;
}
