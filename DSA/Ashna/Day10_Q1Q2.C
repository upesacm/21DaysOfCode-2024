//  Q1
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
void reverseQueue(struct Queue* queue) {
    if (isEmpty(queue))
        return;

    int item = dequeue(queue);
    reverseQueue(queue);
    enqueue(queue, item);
}
void printQueue(struct Queue* queue) {
    if (isEmpty(queue))
        return;

    for (int i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity) {
        printf("%d ", queue->array[i]);
    }
    printf("%d\n", queue->array[queue->rear]);
}

int main() {
    struct Queue* queue = createQueue(MAX);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Original Queue: ");
    printQueue(queue);

    reverseQueue(queue);

    printf("Reversed Queue: ");
    printQueue(queue);

    return 0;
}

//Q2

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}
struct Queue {
    struct Stack* stack1;
    struct Stack* stack2;
};
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}
void enqueue(struct Queue* queue, int item) {
    push(queue->stack1, item);
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

int main() {
    struct Queue* queue = createQueue(MAX);
    enqueue(queue, 1);
    enqueue(queue, 2);
    printf("Dequeued: %d\n", dequeue(queue)); 
    printf("Dequeued: %d\n", dequeue(queue)); 

    return 0;
}

