#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int maxStack[MAX];
int top = -1;
int maxTop = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
    if (maxTop == -1 || x >= maxStack[maxTop]) {
        maxStack[++maxTop] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return;
    }
    if (stack[top] == maxStack[maxTop]) {
        maxTop--;
    }
    top--;
}

int get_max() {
    if (maxTop == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return maxStack[maxTop];
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Get Max\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Max value in stack: %d\n", get_max());
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
