#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 100

typedef struct {
    int data[QUEUE_SIZE];
    int front, rear;
} que;

typedef struct {
    que q1, q2;
} Stack;

void initQueue(que* q) {
    q->front = q->rear = 0;
}

void initStack(Stack* s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void enqueue(que* q, int x) {
    q->data[q->rear++] = x;
}

int dequeue(que* q) {
    return q->data[q->front++];
}

void push(Stack* s, int x) {
    enqueue(&s->q1, x);
}

int pop(Stack* s) {
    if (s->q1.front == s->q1.rear) {
        printf("Stack is empty\n");
        return -1;
    }

    while (s->q1.front != s->q1.rear - 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    int x = dequeue(&s->q1);

    que* temp = &s->q1;
    s->q1 = s->q2;
    s->q2 = *temp;

    return x;
}

int top(Stack* s) {
    if (s->q1.front == s->q1.rear) {
        printf("Stack is empty\n");
        return -1;
    }

    while (s->q1.front != s->q1.rear - 1) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    int x = dequeue(&s->q1);
    enqueue(&s->q2, x);

    que* temp = &s->q1;
    s->q1 = s->q2;
    s->q2 = *temp;

    return x;
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 1);
    push(&s, 2);

    printf("%d\n", top(&s));  

    printf("%d\n", pop(&s));  

    printf("%d\n", top(&s));  

    return 0;
}
