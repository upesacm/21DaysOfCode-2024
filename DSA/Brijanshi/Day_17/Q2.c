#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }

    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    else {
        printf("Value already exists in the BST\n");
    }

    return root;
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

int main() {
    Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    int value = 5;
    root = insertNode(root, value);

    printf("In-order traversal of the updated BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
