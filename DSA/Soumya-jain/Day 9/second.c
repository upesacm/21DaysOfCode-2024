#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    char* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*) malloc(capacity * sizeof(char));
    return stack;
}

bool isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char item) {
    if (isFull(stack)) {
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top--];
}

char top(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->data[stack->top];
}

bool isMatchingPair(char char1, char char2) {
    return (char1 == '(' && char2 == ')') ||
           (char1 == '{' && char2 == '}') ||
           (char1 == '[' && char2 == ']');
}

bool isBalanced(char* expr) {
    int length = 0;
    while (expr[length] != '\0') {
        length++;
    }

    Stack* stack = createStack(length);

    for (int i = 0; i < length; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(stack, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(stack) || !isMatchingPair(pop(stack), expr[i])) {
                free(stack->data);
                free(stack);
                return false;
            }
        }
    }

    bool balanced = isEmpty(stack);
    free(stack->data);
    free(stack);
    return balanced;
}

int main() {
    char expr[] = "{()}[]";

    if (isBalanced(expr)) {
        printf("The expression is balanced\n");
    } else {
        printf("The expression is not balanced\n");
    }

    return 0;
}
