#include <stdio.h>

// Define the structure for a binary tree node
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive function to find the height of a binary tree
int height(TreeNode* node) {
    if (node == NULL) {
        return -1; // Height of empty tree is -1
    }
    
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    
    // Return the greater height plus one (for the edge between the current node and its highest child)
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to print the height of a binary tree
void printHeight(TreeNode* root) {
    int heightValue = height(root);
    printf("The height of the binary tree is: %d\n", heightValue);
}

int main() {
    // Example usage
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printHeight(root); // Output: The height of the binary tree is: 3
    
    return 0;
}
