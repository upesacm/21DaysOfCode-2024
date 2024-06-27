/*
Question 1: Write a function to check if a singly linked list contains a cycle. Return "cycle" if a loop exists, otherwise return "no cycle".

Inputs:
A singly linked list.
Output:
"cycle" if there is a cycle, otherwise "no cycle"
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

char* hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return "cycle";
        }
    }
    return "no cycle";
}

//create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next; // Creating a cycle

    printf("%s\n", hasCycle(head)); 

    // Breaking the cycle
    head->next->next->next->next = NULL;
    printf("%s\n", hasCycle(head));

    return 0;
}
