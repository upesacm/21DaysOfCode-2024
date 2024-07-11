#include <stdio.h>
#include <stdlib.h>

// Queue node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Stack structure
typedef struct Stack {
    Queue q1;
    Queue q2;
} Stack;

// Function to create a new queue node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to enqueue an element into a queue
void enqueue(Queue* q, int data) {
    Node* node = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

// Function to dequeue an element from a queue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1.front = stack->q1.rear = NULL;
    stack->q2.front = stack->q2.rear = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    enqueue(&stack->q1, data);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->q1.front == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    while (stack->q1.front->next!= NULL) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }
    int data = dequeue(&stack->q1);
    Queue* temp = &stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = *temp;
    return data;
}

// Function to get the top element of the stack
int top(Stack* stack) {
    if (stack->q1.front == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    while (stack->q1.front->next!= NULL) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }
    int data = stack->q1.front->data;
    while (!isEmpty(&stack->q2)) {
        enqueue(&stack->q1, dequeue(&stack->q2));
    }
    return data;
}

// Function to check if a queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

int main() {
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", top(stack)); // Output: 3
    printf("Popped element: %d\n", pop(stack)); // Output: 3
    printf("Top element: %d\n", top(stack)); // Output: 2

    return 0;
}