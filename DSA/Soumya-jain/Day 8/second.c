#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

typedef struct StackUsingQueues {
    Queue queue1;
    Queue queue2;
} StackUsingQueues;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q) {
    int item;
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void initStack(StackUsingQueues *stack) {
    initQueue(&stack->queue1);
    initQueue(&stack->queue2);
}

void push(StackUsingQueues *stack, int value) {
    enqueue(&stack->queue1, value);
}

int pop(StackUsingQueues *stack) {
    if (isQueueEmpty(&stack->queue1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (stack->queue1.front != stack->queue1.rear) {
        enqueue(&stack->queue2, dequeue(&stack->queue1));
    }
    int poppedElement = dequeue(&stack->queue1);
    Queue temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
    return poppedElement;
}

int top(StackUsingQueues *stack) {
    if (isQueueEmpty(&stack->queue1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (stack->queue1.front != stack->queue1.rear) {
        enqueue(&stack->queue2, dequeue(&stack->queue1));
    }
    int topElement = dequeue(&stack->queue1);
    enqueue(&stack->queue2, topElement);
    Queue temp = stack->queue1;
    stack->queue1 = stack->queue2;
    stack->queue2 = temp;
    return topElement;
}

int isEmpty(StackUsingQueues *stack) {
    return isQueueEmpty(&stack->queue1);
}

int main() {
    StackUsingQueues stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    printf("Top element: %d\n", top(&stack)); // Output: 3
    printf("Popped element: %d\n", pop(&stack)); // Output: 3
    printf("Top element: %d\n", top(&stack)); // Output: 2
    printf("Popped element: %d\n", pop(&stack)); // Output: 2
    printf("Popped element: %d\n", pop(&stack)); // Output: 1
    printf("Is stack empty: %d\n", isEmpty(&stack)); // Output: 1

    return 0;
}
