#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;
typedef struct Queue {
    StackNode* stack1;
    StackNode* stack2;
} Queue;
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    return q;
}
void push(StackNode** top, int data) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(StackNode** top) {
    if (*top == NULL) return -1;
    int data = (*top)->data;
    StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}
void enqueue(Queue* q, int data) {
    push(&q->stack1, data);
}
int dequeue(Queue* q) {
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    printf("%d\n", dequeue(q)); // Output: 1
    printf("%d\n", dequeue(q)); // Output: 2
    return 0;
}
