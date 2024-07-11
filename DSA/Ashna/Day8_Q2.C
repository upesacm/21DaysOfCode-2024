#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

typedef struct {
    Queue q1, q2;
} Stack;

void initStack(Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(Stack *s, int value) {
    enqueue(&s->q1, value);
}

int pop(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    while (s->q1.front != s->q1.rear) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    int poppedValue = dequeue(&s->q1);
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    return poppedValue;
}

int top(Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (s->q1.front != s->q1.rear) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    int topValue = dequeue(&s->q1);
    enqueue(&s->q2, topValue);
    Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    return topValue;
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);
    printf("Top: %d\n", top(&s)); // Output: 2
    printf("Pop: %d\n", pop(&s)); // Output: 2
    printf("Top: %d\n", top(&s)); // Output: 1

    return 0;
}
