#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }

    Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;

    free(temp);
    return data;
}

typedef struct Queue {
    Node* stack1;
    Node* stack2;
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = NULL;
    queue->stack2 = NULL;
    return queue;
}

void enqueue(Queue* queue, int data) {
    push(&queue->stack1, data);
}

int dequeue(Queue* queue) {
    if (queue->stack2 == NULL) {
        while (queue->stack1 != NULL) {
            int data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }

    if (queue->stack2 == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int data = pop(&queue->stack2);
    return data;
}

void printQueue(Queue* queue) {
    Node* temp = queue->stack1;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);

    printf("Queue after enqueue(1) and enqueue(2): ");
    printQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Dequeued element: %d\n", dequeue(queue));

    return 0;
}
