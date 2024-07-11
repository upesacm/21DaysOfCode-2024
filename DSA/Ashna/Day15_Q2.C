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

void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    
    struct TreeNode** queue = (struct TreeNode**)malloc(100 * sizeof(struct TreeNode*)); // Assume a maximum of 100 nodes
    int front = 0;
    int rear = 0;

    queue[rear++] = root;
    
    while (front < rear) {
        struct TreeNode* node = queue[front++];
        
        printf("%d ", node->value);
        
        if (node->left) {
            queue[rear++] = node->left;
        }
        
        if (node->right) {
            queue[rear++] = node->right;
        }
    }
    
    free(queue);
}

int main() {

    struct TreeNode* root = newTreeNode(3);
    root->left = newTreeNode(9);
    root->right = newTreeNode(20);
    root->right->left = newTreeNode(15);
    root->right->right = newTreeNode(7);
    
    printf("Level order traversal of the tree: ");
    levelOrderTraversal(root);
    printf("\n");
    
    return 0;
}
