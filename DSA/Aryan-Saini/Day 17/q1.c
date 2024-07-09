#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* findLCA(struct TreeNode* root, int node1, int node2) {
    while (root != NULL) {
      
        if (node1 < root->value && node2 < root->value) {
            root = root->left;
        }
      
        else if (node1 > root->value && node2 > root->value) {
            root = root->right;
        }
        else {
      
            return root;
        }
    }
    return NULL;
}
int main() {

    struct TreeNode* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->right->left = createNode(25);
    root->right->right = createNode(35);


    int node1 = 5;
    int node2 = 30;


    struct TreeNode* lca = findLCA(root, node1, node2);
    if (lca != NULL) {
        printf("The LCA of nodes %d and %d is: %d\n", node1, node2, lca->value);
    } else {
        printf("LCA not found\n");
    }

    return 0;
}
