#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Stack {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
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
        return INT_MIN;
    }
    return stack->data[stack->top];
}

Stack* stack;

Stack* maxStack;

void initialize(int capacity) {
    stack = createStack(capacity);
    maxStack = createStack(capacity);
}

void pushStack(int value) {
    push(stack, value);
    if (isEmpty(maxStack) || value >= top(maxStack)) {
        push(maxStack, value);
    }
}

int popStack() {
    int poppedValue = pop(stack);
    if (poppedValue == top(maxStack)) {
        pop(maxStack);
    }
    return poppedValue;
}

int getMax() {
    return top(maxStack);
}

int main() {
    initialize(10);
    
    pushStack(1);
    pushStack(2);
    printf("Max: %d\n", getMax());
    popStack();
    printf("Max: %d\n", getMax()); 
    return 0;
}
