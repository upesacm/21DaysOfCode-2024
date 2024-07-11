//Q1
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
struct Stack {
    int top;
    int items[MAX];
    int maxItems[MAX]; 
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
void push(struct Stack* stack, int x) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = x;

    if (stack->top == 0) {
        stack->maxItems[stack->top] = x;
    } else {
        stack->maxItems[stack->top] = (x > stack->maxItems[stack->top - 1]) ? x : stack->maxItems[stack->top - 1];
    }
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}
int get_max(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->maxItems[stack->top];
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    printf("Max: %d\n", get_max(stack)); // Output: 2
    pop(stack);
    printf("Max: %d\n", get_max(stack)); // Output: 1

    return 0;
}



//Q2

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Stack {
    int top;
    int items[MAX];
    int maxItems[MAX]; 
};
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}
void push(struct Stack* stack, int x) {
    if (stack->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++(stack->top)] = x;
    if (stack->top == 0) {
        stack->maxItems[stack->top] = x;
    } else {
        stack->maxItems[stack->top] = (x > stack->maxItems[stack->top - 1]) ? x : stack->maxItems[stack->top - 1];
    }
}
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[(stack->top)--];
}

int get_max(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->maxItems[stack->top];
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    printf("Max: %d\n", get_max(stack)); 
    pop(stack);
    printf("Max: %d\n", get_max(stack)); 

    return 0;
}

