#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int height_of_binary_tree(struct TreeNode* root) {
    if (root == NULL)
        return -1;  
    int left_height = height_of_binary_tree(root->left);
    int right_height = height_of_binary_tree(root->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

int main() {
    // Construct the binary tree:
    //       3
    //      / \
    //     2   5
    //    /   / \
    //   1   4   6

    struct TreeNode* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->right->left = newNode(4);
    root->right->right = newNode(6);

    printf("Height of the binary tree: %d\n", height_of_binary_tree(root)); 
    free(root);

    return 0;
}
