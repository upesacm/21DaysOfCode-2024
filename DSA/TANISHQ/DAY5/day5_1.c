#include <stdio.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printReverse(Node* head) {
    // Base case: if the list is empty or contains only one node
    if (head == NULL || head->next == NULL) {
        printf("%d ", head->data);
        return;
    }

    // Find the last node
    Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }

    // Print the elements in reverse order starting from the last node
    printReverse(temp);
    printf("%d ", head->data);
}


int main() {
    // Creating a linked list: 1 -> 2 -> 3
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // Allocate nodes in the heap
    head = (Node*)malloc(sizeof(Node));
    second = (Node*)malloc(sizeof(Node));
    third = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printf("Original Order: ");
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    printf("Reversed Order: ");
    printReverse(head);

    return 0;
}
