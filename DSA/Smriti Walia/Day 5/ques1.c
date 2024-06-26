#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct node {
    int data;
    struct node *next;
};

// Function to reverse the linked list
void reverse(struct node** head_ref) {
    struct node *prevnode = NULL, *current = *head_ref, *nextnode = NULL;
    while (current != NULL) {
        nextnode = current->next;
        current->next = prevnode;
        prevnode = current;
        current = nextnode;
    }
    *head_ref = prevnode;
}

// Function to push a new node to the linked list
void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct node* head = NULL;

    // Add elements to the linked list
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);

    printf("Given linked list:\n");
    printList(head);

    reverse(&head);

    printf("\nReversed linked list:\n");
    printList(head);

    return 0;
}
