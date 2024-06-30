#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        return '\0';  // Stack underflow, return null character
    }
    return stack[top--];
}

int is_matching_pair(char left, char right) {
    if ((left == '(' && right == ')') ||
        (left == '{' && right == '}') ||
        (left == '[' && right == ']')) {
        return 1;
    }
    return 0;
} 


int is_balanced(char* expr) {
    for (int i = 0; i < strlen(expr); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char popped = pop();
            if (!is_matching_pair(popped, expr[i])) {
                return 0;
            }
        }
    }
    return top == -1;  // If stack is empty, brackets are balanced
}

int main() {
    char expr[MAX];
    printf("Enter a string of brackets: ");
    scanf("%s", expr);

    if (is_balanced(expr)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
