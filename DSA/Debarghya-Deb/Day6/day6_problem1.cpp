#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    
public:   
    int value;
    Node* next;
    Node (int value){
        this -> value = value;
        this -> next = nullptr;
    }


};

bool Solution(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        
        if(head -> next == NULL){
            
            return false;
        }
        
        fast = fast -> next -> next;
        slow = slow -> next;
        
        
        if(fast == slow){
            return true;
            break;
        }
    }

    return false;
}


int main(){

    Node* head = new Node(1);
    head -> next = new Node(2);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(4);
    head -> next -> next -> next -> next = head -> next;

    cout<< head -> next << endl;
    cout<< head -> next -> next -> next -> next << endl;
    //So we've create a cycle to the second node.


    
    
    if(Solution(head)){
        cout<< "Cycle" << endl;
    }
    else{
        cout<< "False" << endl;
    }

    
    //We'll use the Floyd Cycle detection approach


    

    return 0;
}