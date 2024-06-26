// Question 1: Given a singly linked list, write a function to print the elements in reverse order.

// Inputs:
// A singly linked list.
// Output:
// The elements of the list in reverse order.
// Example:

// Linked list: 1 -> 2 -> 3

// Output: 3 2 1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* creatNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printlist(struct Node* head){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ->", temp-> data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverselist(struct Node** head){
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;
    }
    *head = prev;
}

struct Node* creatlist(){
    int n, data;
    struct Node *head= NULL, *temp =NULL, *newNode =NULL;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    if(n<=0){
        return head;
    }

    for (int i =0; i<n; i++){
        printf("Enter the data of node %d:\n", i+1);
        scanf("%d", &data);

        newNode = creatNode(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

int main(){
    struct Node* head = creatlist();
    printf("Original linked list:\n");

    printlist(head);
    reverselist(&head);

    printf("Reversed linked list:\n");
    printlist(head);

    return 0;    
}