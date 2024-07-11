#include<iostream>
using namespace std;

struct node{

    int data;
    struct node* next;

    node(int val) : data(val), next(nullptr) {}
};

node* start1 = nullptr;
node* start2 = nullptr;

void create(node*& start, int val) {
    node* temp = new node(val);

    if (start == nullptr) {
        start = temp;
    } else {
        node* current = start;
        while (current->next != nullptr)
            current = current->next;
        current->next = temp;
    }
}

int count_ele(node* start) {
    int count = 0;

    node* current = start;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

bool compare(node *start1, node *start2){

    if(count_ele(start1) != count_ele(start2))
        return false;

    node *current1 = start1;
    node *current2 = start2;

    while(current1->next != nullptr){

        if(current1->data != current2->data)
            return false;

        current1 = current1->next;
        current2 = current2->next;
    }

    if(current1->data != current2->data)
        return false;

    return true;    
}


int main(){

    for(int i = 1; i < 9; i++)
        create(start1, i);

    for(int i = 1; i < 9; i++)
        create(start2, i);    
  
    cout << (compare(start1, start2)?"Both are identical":"Both are different") << endl;
}

