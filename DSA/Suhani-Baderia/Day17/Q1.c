#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* findLCA(struct TreeNode* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->val > n1 && root->val > n2)
        return findLCA(root->left, n1, n2);

    if (root->val < n1 && root->val < n2)
        return findLCA(root->right, n1, n2);

    return root;
}

int main() {

    struct TreeNode* root = newNode(20);
    root->left = newNode(10);
    root->right = newNode(30);
    root->left->left = newNode(5);
    root->left->right = newNode(15);
    root->right->left = newNode(25);
    root->right->right = newNode(35);

    int n1 = 5;
    int n2 = 30;

    struct TreeNode* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", n1, n2, lca->val);
    else
        printf("LCA does not exist\n");

    return 0;
}
