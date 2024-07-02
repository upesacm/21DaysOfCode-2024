#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

PriorityQueue* createPriorityQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->head = NULL;
    return queue;
}

void insert(PriorityQueue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->head == NULL || data < queue->head->data) {
        newNode->next = queue->head;
        queue->head = newNode;
    } else {
        Node* current = queue->head;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int extractMin(PriorityQueue* queue) {
    if (queue->head == NULL) {
        printf("Priority queue is empty\n");
        return -1;
    }

    int minData = queue->head->data;
    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    return minData;
}

void printPriorityQueue(PriorityQueue* queue) {
    Node* temp = queue->head;
    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    PriorityQueue* priority_queue = createPriorityQueue();

    insert(priority_queue, 4);
    insert(priority_queue, 2);

    printPriorityQueue(priority_queue);

    printf("Extracted min: %d\n", extractMin(priority_queue));
    printf("Extracted min: %d\n", extractMin(priority_queue));

    return 0;
}
