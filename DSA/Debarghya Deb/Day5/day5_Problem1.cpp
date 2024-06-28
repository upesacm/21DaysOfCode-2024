#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    
  public:  
        int value;
        Node* next;

        Node(int value){
            this -> value = value;
            this -> next = nullptr;
        }
};


Node* reverse(Node* head){
    if(head -> next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* temp = head;
    Node* forward = head -> next;

    while(temp != NULL){
        temp-> next = prev;
        prev = temp; 
        temp = forward;
        if(forward == NULL){
            break;
        }
        forward = forward -> next;

    }

    return prev;
}

int main(){
    
    

    Node* head = NULL;
    Node* temp = NULL;
    Node* tail = NULL;
    int n;
    cout<<"The no. of elements in the linked list : ";
    cin>>n;
    cout<<endl;
    int value;

    for (int i = 0; i < n; i++){
        cout << "Enter value for node " << i+1 << ": ";
        cin >> value;
        Node* newNode = new Node(value);
        
        if (head == NULL){
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    

    
    
    
    Node* new_head = reverse(head);




    Node* temp_2 = new_head;
    while(temp_2 != NULL){
        cout<<temp_2-> value<<endl;
        temp_2 = temp_2 -> next;
    }


    return 0;
}