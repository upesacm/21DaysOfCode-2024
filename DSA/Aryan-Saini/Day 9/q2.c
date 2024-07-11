#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = value;
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

int isBalanced(char* str) {
    int n = strlen(str);
    Stack* stack = createStack(n);

    for (int i = 0; i < n; i++) {
        char ch = str[i];

  
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stack, ch);
        }
     
        else if (ch == ')' || ch == '}' || ch == ']') {
            char topChar = top(stack);
            if ((ch == ')' && topChar == '(') ||
                (ch == '}' && topChar == '{') ||
                (ch == ']' && topChar == '[')) {
                pop(stack);
            } else {
                return 0; 
            }
        }
    }

    int result = isEmpty(stack);
    free(stack->data);
    free(stack);
    return result;
}

int main() {
    char str[100];
    printf("Enter a string of brackets: ");
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
