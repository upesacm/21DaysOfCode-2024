#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void enqueue(Node** front, Node** rear, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void reverseQueue(Node** front, Node** rear) {
    if (*front == NULL) return;
    Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    reverseQueue(front, rear);
    enqueue(front, rear, temp->data);
    free(temp);
}

void printQueue(Node* front) {
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);

    printf("Original Queue: ");
    printQueue(front);

    reverseQueue(&front, &rear);

    printf("Reversed Queue: ");
    printQueue(front);

    return 0;
}
