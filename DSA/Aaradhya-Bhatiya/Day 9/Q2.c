#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow, cannot push %c\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, cannot pop\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

bool isBalanced(char* str) {
    struct Stack* stack = createStack(MAX_SIZE);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(stack, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return false;
            }
            char top = pop(stack);
            if ((top == '(' && str[i] != ')') ||
                (top == '{' && str[i] != '}') ||
                (top == '[' && str[i] != ']')) {
                free(stack->array);
                free(stack);
                return false;
            }
        }
    }

    bool result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string of brackets: ");
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
