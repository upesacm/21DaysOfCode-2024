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


int heightOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return -1; // Return -1 to indicate the height of an empty tree
    }

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main() {
    struct TreeNode* root = newTreeNode(3);
    root->left = newTreeNode(2);
    root->right = newTreeNode(5);
    root->left->left = newTreeNode(1);
    root->right->left = newTreeNode(4);
    root->right->right = newTreeNode(6);

    printf("The height of the tree is: %d\n", heightOfBinaryTree(root));

    return 0;
}
