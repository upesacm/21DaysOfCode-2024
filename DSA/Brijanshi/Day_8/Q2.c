#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef struct Queue {
    int data[QUEUE_SIZE];
    int front, rear, size;
} Queue;

typedef struct Stack {
    Queue q1, q2;
} Stack;

void initQueue(Queue* q) {
    q->front = q->rear = q->size = 0;
}

void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void enqueue(Queue* q, int x) {
    if (q->size == QUEUE_SIZE) {
        printf("Queue is full\n");
        return;
    }
    q->data[q->rear++] = x;
    q->size++;
    if (q->rear == QUEUE_SIZE) q->rear = 0;
}

int dequeue(Queue* q) {
    if (q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int x = q->data[q->front++];
    q->size--;
    if (q->front == QUEUE_SIZE) q->front = 0;
    return x;
}

void push(Stack* s, int x) {
    enqueue(&s->q1, x);
}

int top(Stack* s) {
    if (s->q1.size == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    while (s->q1.size > 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    int x = dequeue(&s->q1);
    enqueue(&s->q2, x);
    Queue* temp = &s->q1;
    s->q1 = s->q2;
    s->q2 = *temp;
    return x;
}

int pop(Stack* s) {
    if (s->q1.size == 0) {
        printf("Stack is empty\n");
        return -1;
    }
    while (s->q1.size > 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    int x = dequeue(&s->q1);
    Queue* temp = &s->q1;
    s->q1 = s->q2;
    s->q2 = *temp;
    return x;
}

int main() {
    Stack s;
    initStack(&s);
    
    push(&s, 1);
    push(&s, 2);
    printf("%d\n", top(&s));  // Output: 2
    printf("%d\n", pop(&s));  // Output: 2
    printf("%d\n", top(&s));  // Output: 1
    
    return 0;
}
