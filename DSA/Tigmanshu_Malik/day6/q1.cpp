#include<iostream>
using namespace std;

struct node{

    int data;
    node* next;

    node(int val) : data(val), next(nullptr) {}
};

node* start = nullptr;

void create(int val){

    node* temp = new node(val);

    if(start == nullptr)
        start = temp;

    else{

        node* current = start;

        while(current->next != nullptr)
            current = current->next;

        current->next = temp;    

    }    
}

bool cycle(){

    node* slow = start;
    node* fast = start;

    while(fast != nullptr && fast->next != nullptr){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
}