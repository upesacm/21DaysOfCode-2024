#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_node 
{
    int value;
    int max;
    struct Stack_node *next;
} Stack_node;

Stack_node* createNode(int value, int max) 
{
    Stack_node* newNode = (Stack_node*)malloc(sizeof(Stack_node));
    newNode->value = value;
    newNode->max = max;
    newNode->next = NULL;
    return newNode;
}

void push(Stack_node** top, int value) 
{
    int max = (*top == NULL) ? value : ((*top)->max > value ? (*top)->max : value);
    Stack_node* newNode = createNode(value, max);
    newNode->next = *top;
    *top = newNode;
}

void pop(Stack_node** top) 
{
    if (*top == NULL) 
    {
        printf("Stack is empty.\n");
        return;
    }
    Stack_node* temp = *top;
    *top = (*top)->next;
    free(temp);
}

int Maximum(Stack_node* top) 
{
    if (top == NULL) 
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->max;
}

int main() 
{
    Stack_node* stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    printf("Max: %d\n", Maximum(stack)); // Output: 2

    pop(&stack);
    printf("Max: %d\n", Maximum(stack)); // Output: 1

    return 0;
}
