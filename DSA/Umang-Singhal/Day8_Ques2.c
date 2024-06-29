#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Queue {
    int front, rear, size;
    int array[MAX];
} Queue;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->size = 0;
    queue->rear = MAX - 1;
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == MAX);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % MAX;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size = queue->size - 1;
    return item;
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

void push(Stack* stack, int item) {
    enqueue(stack->q2, item);
    while (!isEmpty(stack->q1)) {
        enqueue(stack->q2, dequeue(stack->q1));
    }
    Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
}

int pop(Stack* stack) {
    if (isEmpty(stack->q1))
        return -1;
    return dequeue(stack->q1);
}

int top(Stack* stack) {
    if (isEmpty(stack->q1))
        return -1;
    return stack->q1->array[stack->q1->front];
}

int main() {
    Stack* stack = createStack();
    int choice, value;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Top\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, value);
                break;
            case 2:
                value = pop(stack);
                if (value == -1)
                    printf("Stack is empty\n");
                else
                    printf("Popped value: %d\n", value);
                break;
            case 3:
                value = top(stack);
                if (value == -1)
                    printf("Stack is empty\n");
                else
                    printf("Top value: %d\n", value);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
