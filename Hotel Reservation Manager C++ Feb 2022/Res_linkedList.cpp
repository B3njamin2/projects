#include "Res_linkedList.h"

RequestNode::RequestNode(const Guests_Res_Request* Node){
    node = new Guests_Res_Request(*Node);
}
RequestNode::~RequestNode(){
    delete node;
}
void linkedlist::append(const Guests_Res_Request* data){
    //create new head if there isnt already one
    if(head == NULL){
        head = new RequestNode(data);
        return;
    }
    // find the end of the linked list
    RequestNode* current = head; 
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new RequestNode(data);
}
void linkedlist::deleteRequest(int ID){
    
    if(head == NULL){return;}
    //if the head is deleted create a new head
    RequestNode* temp = NULL;
    if(head->node->get_ID()==ID){
        temp = head->next;
        delete head;
        head = temp;
        return;
    }
    //connect the nodes after the middle node is deleted
    RequestNode* current = head;
    while(current->next != NULL){ 
        if(current->next->node->get_ID()==ID){
            temp = current->next->next; 
            delete current->next;
            current->next = temp;
            return;
        }
        current = current->next; 
    }
    std::cout<<"\n\nReservation ID "<<ID <<" not found\n";
}
const Guests_Res_Request* linkedlist::find(int ID)const{
    RequestNode* current = head;
    while(current != NULL){
        if (current->node->get_ID()==ID){
            return current->node;
        }
        current = current->next;
    }
    std::cout<<"\n\nReservation ID "<<ID <<" not found\n";
    return NULL;
}

void linkedlist::print()const{
    RequestNode* current = head;
    
    std::cout <<"\n\n------------------------Reservation List---------------------------\n";
    while(current != NULL){
        current->node->print();  
        current = current->next;
    }
    std::cout <<"---------------------End of Reservation List-----------------------\n\n";
}
linkedlist::~linkedlist(){
    //runs a loop to delete all the nodes
    RequestNode* current = head;
    RequestNode* next = NULL;
    while(current != NULL){
        next = current->next;
        delete current;
        current = next;
    }
    head=NULL;
    
}
