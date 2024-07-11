#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack element
typedef struct StackElement {
    int data;
    int max;
    struct StackElement* next;
} StackElement;

// Structure to represent the stack
typedef struct Stack {
    StackElement* top;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(Stack* stack, int data) {
    StackElement* element = (StackElement*)malloc(sizeof(StackElement));
    element->data = data;
    element->max = (stack->top == NULL) ? data : (data > stack->top->max) ? data : stack->top->max;
    element->next = stack->top;
    stack->top = element;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    StackElement* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

// Function to retrieve the maximum element from the stack
int getMax(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->max;
}

// Function to print the stack
void printStack(Stack* stack) {
    StackElement* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = createStack();

    push(stack, 5);
    push(stack, 10);
    push(stack, 3);
    push(stack, 15);
    push(stack, 8);

    printf("Stack: ");
    printStack(stack);

    printf("Max element: %d\n", getMax(stack));

    pop(stack);
    printf("Stack: ");
    printStack(stack);

    printf("Max element: %d\n", getMax(stack));

    return 0;
}