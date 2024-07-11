#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left!= NULL) {
            queue[rear++] = current->left;
        }
        if (current->right!= NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = 3;
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->data = 9;
    root->right->data = 20;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right->left = (Node*)malloc(sizeof(Node));
    root->right->right = (Node*)malloc(sizeof(Node));
    root->right->left->data = 15;
    root->right->right->data = 7;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    levelOrderTraversal(root);

    return 0;
}
