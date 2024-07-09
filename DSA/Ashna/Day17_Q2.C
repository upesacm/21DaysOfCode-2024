#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newTreeNode(int x) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = x;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new value into the BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newTreeNode(val);
    }
    if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }
    return root;
}

// Function to perform inorder traversal of the BST
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

int main() {
    // Create the initial BST
    struct TreeNode* root = newTreeNode(4);
    root->left = newTreeNode(2);
    root->right = newTreeNode(7);
    root->left->left = newTreeNode(1);
    root->left->right = newTreeNode(3);

    // Print the inorder traversal of the original BST
    printf("Inorder traversal of the original BST: ");
    inorderTraversal(root);
    printf("\n");

    // Insert a new value into the BST
    int val = 5;
    root = insertIntoBST(root, val);

    // Print the inorder traversal of the BST after inserting the new value
    printf("Inorder traversal of the BST after inserting %d: ", val);
    inorderTraversal(root);
    printf("\n");

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
