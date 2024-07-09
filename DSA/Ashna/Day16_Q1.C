#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newTreeNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    postorderTraversal(root->left);
    
    postorderTraversal(root->right);
    
    printf("%d ", root->value);
}

int main() {
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    
    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    return 0;
}
