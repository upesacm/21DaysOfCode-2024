#include<iostream>
using namespace std;

struct node{

    int data;
    struct node* next;

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

void display_reverse(node* start){

    if(start->next == nullptr){
        cout << start->data << " ";
        return;
    }

    display_reverse(start->next);

    cout << start->data << " " ;
}

int main(){

    for(int i = 1; i < 6; i++)
        create(i);

    display_reverse(start);    
}

