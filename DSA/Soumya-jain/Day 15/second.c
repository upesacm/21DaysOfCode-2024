#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Helper function to create a new tree node.
struct TreeNode* newNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Definition for a queue node.
struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
};

// Definition for a queue.
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Helper function to create a new queue node.
struct QueueNode* newQueueNode(struct TreeNode* treeNode) {
    struct QueueNode* qNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    qNode->treeNode = treeNode;
    qNode->next = NULL;
    return qNode;
}

// Helper function to create a queue.
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty.
int isQueueEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Function to add a tree node to the queue.
void enqueue(struct Queue* queue, struct TreeNode* treeNode) {
    struct QueueNode* qNode = newQueueNode(treeNode);
    if (queue->rear == NULL) {
        queue->front = queue->rear = qNode;
        return;
    }
    queue->rear->next = qNode;
    queue->rear = qNode;
}

// Function to remove a tree node from the queue.
struct TreeNode* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue))
        return NULL;
    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    struct TreeNode* treeNode = temp->treeNode;
    free(temp);
    return treeNode;
}

// Function to perform level order traversal of a binary tree.
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        struct TreeNode* current = dequeue(queue);
        printf("%d ", current->value);

        if (current->left != NULL)
            enqueue(queue, current->left);
        if (current->right != NULL)
            enqueue(queue, current->right);
    }

    // Free the queue.
    free(queue);
}

int main() {
    // Construct the binary tree:
    //       3
    //      / \
    //     9  20
    //       / \
    //      15  7

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    // Free allocated memory (not shown for brevity).

    return 0;
}
