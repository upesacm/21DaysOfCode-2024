#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a stack
typedef struct Stack {
    char data;
    struct Stack* next;
} Stack;

// Function to create a new stack
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->next = NULL;
    return stack;
}

// Function to push an element onto the stack
void push(Stack** stack, char data) {
    Stack* element = (Stack*)malloc(sizeof(Stack));
    element->data = data;
    element->next = *stack;
    *stack = element;
}

// Function to pop an element from the stack
char pop(Stack** stack) {
    if (*stack == NULL) {
        printf("Stack is empty\n");
        return '\0';
    }
    char data = (*stack)->data;
    Stack* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return data;
}

// Function to check if a given string of brackets is balanced
char* isBalanced(char* brackets) {
    Stack* stack = createStack();
    char* result = "YES";

    for (int i = 0; i < strlen(brackets); i++) {
        char bracket = brackets[i];
        if (bracket == '(' || bracket == '{' || bracket == '[') {
            push(&stack, bracket);
        } else {
            char top = pop(&stack);
            if ((bracket == ')' && top != '(') ||
                (bracket == '}' && top != '{') ||
                (bracket == ']' && top != '[')) {
                result = "NO";
                break;
            }
        }
    }

    if (stack != NULL) {
        result = "NO";
    }

    return result;
}

int main() {
    char brackets[] = "({[]})";
    printf("%s\n", isBalanced(brackets)); // Output: YES

    char brackets2[] = "({[}]})";
    printf("%s\n", isBalanced(brackets2)); // Output: NO

    return 0;
}