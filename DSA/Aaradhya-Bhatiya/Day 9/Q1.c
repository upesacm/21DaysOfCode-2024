#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

struct MaxStack {
    struct Stack* stack;
    struct Stack* max_stack;
};

struct MaxStack* createMaxStack(unsigned capacity) {
    struct MaxStack* maxStack = (struct MaxStack*) malloc(sizeof(struct MaxStack));
    maxStack->stack = createStack(capacity);
    maxStack->max_stack = createStack(capacity);
    return maxStack;
}

void pushMax(struct MaxStack* maxStack, int item) {
    push(maxStack->stack, item);
    if (isEmpty(maxStack->max_stack) || item >= peek(maxStack->max_stack)) {
        push(maxStack->max_stack, item);
    }
}

int popMax(struct MaxStack* maxStack) {
    int poppedValue = pop(maxStack->stack);
    if (poppedValue == peek(maxStack->max_stack)) {
        pop(maxStack->max_stack);
    }
    return poppedValue;
}

int getMax(struct MaxStack* maxStack) {
    if (isEmpty(maxStack->max_stack)) {
        printf("Stack is empty\n");
        return INT_MIN;
    }
    return peek(maxStack->max_stack);
}


int main() {
    int capacity, choice, value;

    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    struct MaxStack* maxStack = createMaxStack(capacity);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Get Max\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                pushMax(maxStack, value);
                break;
            case 2:
                value = popMax(maxStack);
                if (value != INT_MIN) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                value = getMax(maxStack);
                if (value != INT_MIN) {
                    printf("Maximum element is %d\n", value);
                }
                break;
            case 4:
                printf("Exiting...\n");
                free(maxStack->stack->array);
                free(maxStack->stack);
                free(maxStack->max_stack->array);
                free(maxStack->max_stack);
                free(maxStack);
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}
