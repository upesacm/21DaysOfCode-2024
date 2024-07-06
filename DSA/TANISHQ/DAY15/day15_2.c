#include <stdio.h>
#include <stdlib.h>

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

// Function to perform level order traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return; // Base case: if the tree is empty
    }
    
    // Create a queue and enqueue the root node
    TreeNode* queue[100]; // Assuming a max size of 100 for simplicity
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    // While the queue is not empty
    while (front != rear) {
        // Dequeue a node from the front of the queue
        TreeNode* currentNode = queue[front++];
        
        // Visit the dequeued node
        printf("%d ", currentNode->val);
        
        // Enqueue the left child of the current node, if it exists
        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }
        
        // Enqueue the right child of the current node, if it exists
        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }
    }
}

int main() {
    // Example usage
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    printf("Level Order Traversal: ");
    levelOrderTraversal(root); // Output: Level Order Traversal: 1 2 3 4 5
    
    return 0;
}
