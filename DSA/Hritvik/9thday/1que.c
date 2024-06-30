#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int maxVal;
    struct Node* next;
} Node;

Node* createNode(int value, int maxVal) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->maxVal = maxVal;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Node* root) {
    return root == NULL;
}

void push(Node** root, int value) {
    int maxVal = isEmpty(*root) ? value : ((*root)->maxVal > value ? (*root)->maxVal : value);
    Node* newNode = createNode(value, maxVal);
    newNode->next = *root;
    *root = newNode;
    printf("Pushed %d\n", value);
}

int pop(Node** root) {
    if (isEmpty(*root)) {
        printf("Stack is empty\n");
        return -1;
    }
    Node* temp = *root;
    *root = (*root)->next;
    int value = temp->value;
    free(temp);
    return value;
}

int getMax(Node* root) {
    return isEmpty(root) ? -1 : root->maxVal;
}

int main() {
    Node* stack = NULL;
    push(&stack, 1);
    push(&stack, 2);
    printf("Max value: %d\n", getMax(stack));
    pop(&stack);
    printf("Max value: %d\n", getMax(stack));
    return 0;
}
