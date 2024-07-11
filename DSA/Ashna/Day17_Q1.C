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

// Function to find the lowest common ancestor in a BST
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL) return NULL;
    if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

int main() {
    // Create the tree nodes
    struct TreeNode* root = newTreeNode(20);
    root->left = newTreeNode(10);
    root->right = newTreeNode(30);
    root->left->left = newTreeNode(5);
    root->left->right = newTreeNode(15);
    root->right->left = newTreeNode(25);
    root->right->right = newTreeNode(35);

    struct TreeNode* p = root->left->left;  
    struct TreeNode* q = root->right;

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        printf("The LCA of nodes %d and %d is %d\n", p->val, q->val, lca->val);
    } else {
        printf("LCA not found.\n");
    }


    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
