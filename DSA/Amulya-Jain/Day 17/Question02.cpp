// Insert a Value into a BST
#include <stdio.h>
#include <stdlib.h>

// structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    // Construct the BST
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int value = 5;
    root = insert(root, value);

    printf("Inorder traversal of the updated BST: ");
    inorder(root);
    printf("\n");

    return 0;
}

/*
BST:
       20
      /  \
    10    30
   /  \  /  \
  5   15 25  35

Nodes: 5, 30
Output: 20

*/
