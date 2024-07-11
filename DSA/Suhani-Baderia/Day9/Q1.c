#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    int data;
    int max;
    struct StackNode* next;
} StackNode;

StackNode* createNode(int data, int max) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->max = max;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {
    int max = data;
    if (!isEmpty(*root)) {
        max = (*root)->max > data ? (*root)->max : data;
    }
    StackNode* newNode = createNode(data, max);
    newNode->next = *root;
    *root = newNode;
    printf("Pushed %d to the stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty\n");
        return -1;
    }
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int getMax(StackNode* root) {
    if (isEmpty(root)) {
        printf("Stack is empty\n");
        return -1;
    }
    return root->max;
}

int main() {
    StackNode* root = NULL;

    push(&root, 1);
    push(&root, 2);
    printf("Max element: %d\n", getMax(root));

    pop(&root);
    printf("Max element: %d\n", getMax(root));

    return 0;
}
