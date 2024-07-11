#include <stdio.h>
#include <stdlib.h>
void push(int *stack, int *top, int value) {
    stack[++(*top)] = value;
}
int pop(int *stack, int *top) {
    return stack[(*top)--];
}
int isEmpty(int top) {
    return top == -1;
}
void enqueue(int *stack1, int *top1, int value) {
    push(stack1, top1, value);
}
int dequeue(int *stack1, int *top1, int *stack2, int *top2) {
    if (isEmpty(*top2)) {
        while (!isEmpty(*top1)) {
            push(stack2, top2, pop(stack1, top1));
        }
    }
    return pop(stack2, top2);
}
int main() {
    int n, choice, value;
    int top1 = -1, top2 = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    int *stack1 = (int *)malloc(n * sizeof(int));
    int *stack2 = (int *)malloc(n * sizeof(int));
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (top1 == n - 1) {
                    printf("Queue is full!\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(stack1, &top1, value);
                }
                break;
            case 2:
                if (isEmpty(top1) && isEmpty(top2)) {
                    printf("Queue is empty!\n");
                } else {
                    value = dequeue(stack1, &top1, stack2, &top2);
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                free(stack1);
                free(stack2);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
