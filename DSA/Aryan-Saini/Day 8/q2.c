#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q) {
    if (q->front == NULL)
        return -1;  

    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}


int isEmpty(Queue* q) {
    return q->front == NULL;
}


typedef struct Stack {
    Queue* q1;
    Queue* q2;
} Stack;


Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}


void push(Stack* stack, int data) {
    enqueue(stack->q1, data);
}

int pop(Stack* stack) {
    if (isEmpty(stack->q1))
        return -1; 

    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    int data = dequeue(stack->q1);

    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return data;
}

int top(Stack* stack) {
    if (isEmpty(stack->q1))
        return -1;  // Stack is empty

    while (stack->q1->front->next != NULL) {
        enqueue(stack->q2, dequeue(stack->q1));
    }

    int data = stack->q1->front->data;
    enqueue(stack->q2, dequeue(stack->q1));

    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return data;
}

int main() {
    Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    printf("Top element: %d\n", top(stack)); 
    printf("Popped element: %d\n", pop(stack)); 
    printf("Top element: %d\n", top(stack)); 

    return 0;
}
