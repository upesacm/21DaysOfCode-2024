#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack node
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

// Structure to represent a queue
typedef struct Queue {
    StackNode* stack1; // stack for enqueue
    StackNode* stack2; // stack for dequeue
} Queue;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    return q;
}

// Function to push an element onto a stack
void push(StackNode** stack, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *stack;
    *stack = newNode;
}

// Function to pop an element from a stack
int pop(StackNode** stack) {
    if (*stack == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = (*stack)->data;
    StackNode* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

// Function to enqueue an element into the queue
void enqueue(Queue* q, int data) {
    push(&q->stack1, data);
}

// Function to dequeue an element from the queue
int dequeue(Queue* q) {
    if (q->stack2 == NULL) {
        // transfer elements from stack1 to stack2
        while (q->stack1!= NULL) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}

// Function to print the queue
void printQueue(Queue* q) {
    StackNode* temp = q->stack2;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    // Enqueue elements
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);

    printf("Queue: ");
    printQueue(q);

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));

    printf("Queue: ");
    printQueue(q);

    return 0;
}