#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {
    Node* head;
} PriorityQueue;
void initQueue(PriorityQueue* pq) {
    pq->head = NULL;
}
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(PriorityQueue* pq, int element) {
    Node* temp = newNode(element);
    if (pq->head == NULL || pq->head->data > element) {
        temp->next = pq->head;
        pq->head = temp;
    } else {
        Node* current = pq->head;
        while (current->next != NULL && current->next->data <= element) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}
int extractMin(PriorityQueue* pq) {
    if (pq->head == NULL) {
        printf("Priority queue is empty\n");
        return -1; // Indicate that the queue is empty
    }

    Node* temp = pq->head;
    int minElement = temp->data;
    pq->head = pq->head->next;
    free(temp);

    return minElement;
}
void printQueue(PriorityQueue* pq) {
    Node* current = pq->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    insert(&pq, 4);
    insert(&pq, 2);
    insert(&pq, 5);
    insert(&pq, 1);

    printQueue(&pq); 

    printf("Extracted min: %d\n", extractMin()); // Output: 1
    printf("Extracted min: %d\n", extractMin()); // Output: 2
    printf("Extracted min: %d\n", extractMin()); // Output: 4
    printf("Extracted min: %d\n", extractMin()); // Output: 5
    printf("Extracted min: %d\n", extractMin()); // Output: Priority queue is empty

    return 0;
}
