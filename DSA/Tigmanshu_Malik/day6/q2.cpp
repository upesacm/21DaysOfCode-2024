#include<iostream>
using namespace std;

struct node{

    int data;
    struct node* next;

    node(int val) : data(val), next(nullptr) {}
};

int merge(node *start1, node *start2){

    node* ptr1 = start1;
    node* ptr2 = start2;

    while(ptr1 != ptr2){

        if(ptr1 == nullptr)
            ptr1 = start2;

        else
            ptr1 = ptr1->next;

        if(ptr2 == nullptr)
            ptr2 = start1;

        else
            ptr2 = ptr2->next;    
        
    }

    if(ptr1 != nullptr)
        return ptr1->data;

    return -1;    
}   