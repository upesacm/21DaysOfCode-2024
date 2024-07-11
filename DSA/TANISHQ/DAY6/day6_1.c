#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to check if a singly linked list contains a cycle
char* hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast!= NULL && fast->next!= NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return "cycle";
        }
    }

    return "no cycle";
}

// Example usage
int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = malloc(sizeof(Node));
    head->next->next->next->data = 4;
    head->next->next->next->next = head->next; // create a cycle

    printf("%s\n", hasCycle(head)); // Output: cycle

    return 0;
}