#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*) malloc(capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return INT_MIN;
    }
    return stack->data[stack->top--];
}

int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->data[stack->top];
}

typedef struct MaxStack {
    Stack* mainStack;
    Stack* maxStack;
} MaxStack;

MaxStack* createMaxStack(int capacity) {
    MaxStack* maxStack = (MaxStack*) malloc(sizeof(MaxStack));
    maxStack->mainStack = createStack(capacity);
    maxStack->maxStack = createStack(capacity);
    return maxStack;
}

void maxPush(MaxStack* maxStack, int item) {
    push(maxStack->mainStack, item);
    if (isEmpty(maxStack->maxStack) || item >= top(maxStack->maxStack)) {
        push(maxStack->maxStack, item);
    }
}

int maxPop(MaxStack* maxStack) {
    int popped = pop(maxStack->mainStack);
    if (popped == top(maxStack->maxStack)) {
        pop(maxStack->maxStack);
    }
    return popped;
}

int getMax(MaxStack* maxStack) {
    return top(maxStack->maxStack);
}

int main() {
    MaxStack* maxStack = createMaxStack(10);

    maxPush(maxStack, 3);
    maxPush(maxStack, 1);
    maxPush(maxStack, 5);
    maxPush(maxStack, 2);

    printf("Max: %d\n", getMax(maxStack)); 
    maxPop(maxStack);
    printf("Max: %d\n", getMax(maxStack)); 
    maxPop(maxStack);
    printf("Max: %d\n", getMax(maxStack)); 

    
    free(maxStack->mainStack->data);
    free(maxStack->maxStack->data);
    free(maxStack->mainStack);
    free(maxStack->maxStack);
    free(maxStack);

    return 0;
}
