//  To Find the Lowest Common Ancestor (LCA)
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

// Function to find the LCA of two nodes in a BST
struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    else if (root->data > n1 && root->data > n2) 
        return findLCA(root->left, n1, n2);
    else if (root->data < n1 && root->data < n2) 
        return findLCA(root->right, n1, n2);
    return root;
}

int main() {
    // Construct the BST
    struct Node* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    int n1 = 5, n2 = 30;
    struct Node* lca = findLCA(root, n1, n2);

    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
    else
        printf("LCA does not exist\n");

    return 0;
}
