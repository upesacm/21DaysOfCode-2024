#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack {
    Queue queue1, queue2;
} Stack;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void initStack(Stack* s) {
    initQueue(&s->queue1);
    initQueue(&s->queue2);
}

void enqueue(Queue* q, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    int element = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return element;
}

bool isEmpty(Stack* s) {
    return s->queue1.front == NULL && s->queue2.front == NULL;
}

void push(Stack* s, int value) {
    if (!isEmpty(s)) {
        enqueue(&s->queue1, value);
    } else {
        enqueue(&s->queue2, value);
    }
}

int pop(Stack* s) {
    Queue* nonEmptyQueue = s->queue1.front != NULL ? &s->queue1 : &s->queue2;
    Queue* emptyQueue = s->queue1.front != NULL ? &s->queue2 : &s->queue1;

    while (nonEmptyQueue->front->next != NULL) {
        enqueue(emptyQueue, dequeue(nonEmptyQueue));
    }

    return dequeue(nonEmptyQueue);
}

int top(Stack* s) {
    Queue* nonEmptyQueue = s->queue1.front != NULL ? &s->queue1 : &s->queue2;
    Queue* emptyQueue = s->queue1.front != NULL ? &s->queue2 : &s->queue1;

    while (nonEmptyQueue->front->next != NULL) {
        enqueue(emptyQueue, dequeue(nonEmptyQueue));
    }

    int topElement = dequeue(nonEmptyQueue);
    enqueue(emptyQueue, topElement);
    return topElement;
}

int size(Stack* s) {
    int size1 = 0, size2 = 0;
    Node* temp1 = s->queue1.front, *temp2 = s->queue2.front;

    while (temp1 != NULL) {
        size1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        size2++;
        temp2 = temp2->next;
    }

    return size1 + size2;
}

int main() {
    Stack stack;
    initStack(&stack);

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Top\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                int value;
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                if (!isEmpty(&stack)) {
                    printf("Popped value: %d\n", pop(&stack));
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 3:
                if (!isEmpty(&stack)) {
                    printf("Top value: %d\n", top(&stack));
                } else {
                    printf("Stack is empty.\n");
                }
                break;
            case 4:
                printf("Exiting.\n");
                return 0;  
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;  
}