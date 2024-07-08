#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct QueueNode {
    struct TreeNode* treeNode;
    int hd;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

struct QueueNode* newQueueNode(struct TreeNode* treeNode, int hd) {
    struct QueueNode* node = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    node->treeNode = treeNode;
    node->hd = hd;
    node->next = NULL;
    return node;
}

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue a node into the queue
void enqueue(struct Queue* queue, struct TreeNode* treeNode, int hd) {
    struct QueueNode* node = newQueueNode(treeNode, hd);
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

// Function to dequeue a node from the queue
struct QueueNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    return temp;
}

// Function to find the top view of a binary tree
void topView(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Create a map to store horizontal distance and corresponding node's data
    int hdNodeMap[1000] = {0};  // Assuming the tree will not have a horizontal distance beyond [-500, 500]
    int hdSeen[1000] = {0};     // To keep track of seen horizontal distances
    struct Queue* queue = createQueue();
    enqueue(queue, root, 500);  // Using 500 as the middle point for horizontal distance

    while (queue->front != NULL) {
        struct QueueNode* temp = dequeue(queue);
        struct TreeNode* node = temp->treeNode;
        int hd = temp->hd;
        free(temp);

        if (!hdSeen[hd]) {
            hdSeen[hd] = 1;
            hdNodeMap[hd] = node->data;
        }

        if (node->left) {
            enqueue(queue, node->left, hd - 1);
        }
        if (node->right) {
            enqueue(queue, node->right, hd + 1);
        }
    }

    // Print the top view nodes
    for (int i = 0; i < 1000; i++) {
        if (hdSeen[i]) {
            printf("%d ", hdNodeMap[i]);
        }
    }
    printf("\n");

    free(queue);
}

int main() {
    struct TreeNode* root = newTreeNode(1);
    root->left = newTreeNode(2);
    root->right = newTreeNode(3);
    root->left->left = newTreeNode(4);
    root->left->right = newTreeNode(5);
    root->right->left = newTreeNode(6);
    root->right->right = newTreeNode(7);

    printf("Top view of the binary tree is: ");
    topView(root);

  
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
