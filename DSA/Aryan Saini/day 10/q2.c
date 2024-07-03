#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};


struct StackNode* newStackNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}


int isStackEmpty(struct StackNode* root) {
    return !root;
}


void push(struct StackNode** root, int data) {
    struct StackNode* stackNode = newStackNode(data);
    stackNode->next = *root;
    *root = stackNode;
}


int pop(struct StackNode** root) {
    if (isStackEmpty(*root))
        return -1;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}


struct Queue {
    struct StackNode* stack1;
    struct StackNode* stack2;
};


struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->stack1 = NULL;
    queue->stack2 = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int data) {
    push(&queue->stack1, data);
}


int dequeue(struct Queue* queue) {
    int data;

    if (isStackEmpty(queue->stack1) && isStackEmpty(queue->stack2)) {
        printf("Queue is empty\n");
        return -1;
    }


    if (isStackEmpty(queue->stack2)) {
        while (!isStackEmpty(queue->stack1)) {
            data = pop(&queue->stack1);
            push(&queue->stack2, data);
        }
    }


    return pop(&queue->stack2);
}

int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeue: %d\n", dequeue(queue)); 
    printf("Dequeue: %d\n", dequeue(queue)); 
    printf("Dequeue: %d\n", dequeue(queue)); 
    printf("Dequeue: %d\n", dequeue(queue)); 

    return 0;
}
