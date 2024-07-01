#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add an element to the queue
void enqueue(Node** queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *queue;
    *queue = newNode;
}

// Function to reverse a queue using recursive calls
void reverseQueue(Node** queue) {
    if (*queue == NULL || (*queue)->next == NULL) {
        return;
    }

    Node* temp = *queue;
    *queue = (*queue)->next;
    reverseQueue(queue);
    temp->next->next = temp;
    temp->next = NULL;
}

// Function to print the queue
void printQueue(Node* queue) {
    while (queue!= NULL) {
        printf("%d ", queue->data);
        queue = queue->next;
    }
    printf("\n");
}

int main() {
    Node* queue = NULL;

    // Add elements to the queue
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    printf("Original Queue: ");
    printQueue(queue);

    // Reverse the queue
    reverseQueue(&queue);

    printf("Reversed Queue: ");
    printQueue(queue);

    return 0;
}