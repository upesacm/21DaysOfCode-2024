#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(Queue* q) {
    return q->rear == -1;
}


void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}


int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack* stack) {
    initQueue(&stack->q1);
    initQueue(&stack->q2);
}

void push(Stack* stack, int value) {
    enqueue(&stack->q1, value);
}

int pop(Stack* stack) {
    if (isEmpty(&stack->q1)) {
        printf("Stack is empty\n");
        return -1;
    }

    while (stack->q1.front != stack->q1.rear) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }

    int poppedValue = dequeue(&stack->q1);

    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return poppedValue;
}

int top(Stack* stack) {
    if (isEmpty(&stack->q1)) {
        printf("Stack is empty\n");
        return -1;
    }

    while (stack->q1.front != stack->q1.rear) {
        enqueue(&stack->q2, dequeue(&stack->q1));
    }

    int topValue = front(&stack->q1);
    enqueue(&stack->q2, dequeue(&stack->q1));

    Queue temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;

    return topValue;
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    printf("Top element: %d\n", top(&stack)); // Output: 2
    printf("Popped element: %d\n", pop(&stack)); // Output: 2
    printf("Top element: %d\n", top(&stack)); // Output: 1

    return 0;
}
