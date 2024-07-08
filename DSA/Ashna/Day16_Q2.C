#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newTreeNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to perform inorder traversal of a binary tree
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);

    printf("%d ", root->value);
  
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    return 0;
}
