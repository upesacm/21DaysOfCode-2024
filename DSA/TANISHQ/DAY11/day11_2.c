#include <stdio.h>
#include <stdlib.h>

// Structure to represent a priority queue node
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// Structure to represent the priority queue
typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

// Function to create a new priority queue node
Node* createNode(int data, int priority) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

// Function to insert a new element into the priority queue
void insert(PriorityQueue* queue, int data, int priority) {
    Node* node = createNode(data, priority);
    if (queue->head == NULL || priority < queue->head->priority) {
        node->next = queue->head;
        queue->head = node;
    } else {
        Node* current = queue->head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

// Function to extract the minimum element from the priority queue
int extractMin(PriorityQueue* queue) {
    if (queue->head == NULL) {
        printf("Priority queue is empty\n");
        return -1;
    }
    int min = queue->head->data;
    Node* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    return min;
}

// Function to print the priority queue
void printQueue(PriorityQueue* queue) {
    Node* current = queue->head;
    while (current != NULL) {
        printf("%d (%d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    PriorityQueue queue;
    queue.head = NULL;

    insert(&queue, 5, 3);
    insert(&queue, 2, 1);
    insert(&queue, 8, 4);
    insert(&queue, 3, 2);

    printf("Priority queue: ");
    printQueue(&queue);

    int min = extractMin(&queue);
    printf("Extracted min: %d\n", min);

    printf("Priority queue: ");
    printQueue(&queue);

    return 0;
}