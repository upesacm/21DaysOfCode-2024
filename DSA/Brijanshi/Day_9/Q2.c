#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Stack {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

void push(Stack* s, char x) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack is full\n");
        return;
    }
    s->data[++s->top] = x;
}

char pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top--];
}

int isBalanced(char* str) {
    Stack s;
    initStack(&s);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&s, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (s.top == -1) return 0;
            char top = pop(&s);
            if ((str[i] == ')' && top!= '(') ||
                (str[i] == '}' && top!= '{') ||
                (str[i] == ']' && top!= '[')) {
                return 0;
            }
        }
    }
    return s.top == -1;
}

int main() {
    char str[] = "{[()]}";
    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
