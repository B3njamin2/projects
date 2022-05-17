#pragma once
#include "Guests_Res_Request.h"
#include <iostream>


// A linkedlist was made to store and manipulate the Guests_Res_Request list in the Reservation manager
class RequestNode{
    RequestNode* next{NULL};
    Guests_Res_Request* node;
    RequestNode(const Guests_Res_Request*);
    friend class linkedlist;
    ~RequestNode();
};
class linkedlist{
    RequestNode* head{NULL};
    linkedlist(){};

    void append(const Guests_Res_Request*);// add request
    void deleteRequest(int); // delete request

    public:
    const Guests_Res_Request* find(int)const; //Find and return Guest_res_request according to the id
    
    
    // print function & destructor
    void print()const;// print the guest info list
    ~linkedlist();
    friend class Reservation_Manager;
};
