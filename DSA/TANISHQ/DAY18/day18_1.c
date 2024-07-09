#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to perform a level order traversal and find the top view
void topView(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Create a queue for level order traversal
    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    // Create a map to store the top view nodes
    int map[100] = {0};
    int min = 0, max = 0;

    while (front < rear) {
        TreeNode* node = queue[front++];
        if (node->left) {
            queue[rear++] = node->left;
            min = node->left->data < min ? node->left->data : min;
        }
        if (node->right) {
            queue[rear++] = node->right;
            max = node->right->data > max ? node->right->data : max;
        }

        // Mark the node as visited
        map[node->data] = 1;
    }

    // Print the top view nodes
    for (int i = min; i <= max; i++) {
        if (map[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Driver code
int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->left->right->right = createNode(5);
    root->left->right->right->right = createNode(6);

    topView(root);

    return 0;
}