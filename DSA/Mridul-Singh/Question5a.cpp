#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node* next;
}node;

node* head;

void insertAtBegin(int data){
    node * temp;
    temp=(node *)(malloc(sizeof(node)));
    temp->data=data;
    temp->next=head;
    head=temp;
}

void insertAtEnd(int data){
    node* ptr;
    ptr=head;
    node *temp;
    temp=(node *)(malloc(sizeof(node)));
    if(head==NULL){
        temp->data=data;
        temp->next=NULL;
        head=temp;
    }
    else{
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        temp->data=data;
        temp->next=NULL;
        ptr->next=temp;
    }
}

void display(){
    if(head==NULL){
        cout << "Empty";
    }
    else{
        node* ptr;
        ptr=head;
        while(ptr!=NULL){
            printf("%d  ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    
}

//Time complexity of this function is O(n) and space is also O(n)
void reverseUsingStack(node* temp){
    stack<int> st;
    if(temp==NULL){
        printf("Empty");
    }
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    while (!st.empty()) {
        int element = st.top();
        cout << element << "  ";
        st.pop();
  }
}

//Time complexity of this function is O(n) and space is also O(n)
void reverseUsingRecursion(node* temp){
    if(temp==NULL){
        return ;
    }
    reverse(temp->next);
    printf("%d  ",temp->data);
}

int main(){
    insertAtBegin(1);
    insertAtBegin(2);
    insertAtEnd(5);
    insertAtEnd(6);
    insertAtEnd(7);
    display();
    node* temp=head;
    reverseUsingStack(temp);
    // reverseUsingRecursion(temp);
    return 0;
}