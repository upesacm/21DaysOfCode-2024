#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new BST node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
Node* insertNode(Node* root, int data) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return createNode(data);
    }

    // If the data is less than the root's data, insert it in the left subtree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    // If the data is greater than the root's data, insert it in the right subtree
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // If the data is equal to the root's data, do nothing (to avoid duplicates)
    else {
        return root;
    }

    return root;
}

// Example usage:
int main() {
    // Create a sample BST
    Node* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 20);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 15);
    root = insertNode(root, 25);

    // Print the updated BST
    printf("Updated BST:\n");
    printBST(root);

    return 0;
}

// Helper function to print the BST in inorder traversal
void printBST(Node* root) {
    if (root == NULL) {
        return;
    }

    printBST(root->left);
    printf("%d ", root->data);
    printBST(root->right);
}