#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int leftChild[MAX_SIZE];
int rightChild[MAX_SIZE];
int queue[MAX_SIZE];
int front = 0, rear = 0;
void enqueue(int value) {
    if (rear < MAX_SIZE) {
        queue[rear++] = value;
    }
}
int dequeue() {
    if (front < rear) {
        return queue[front++];
    }
    return -1;
}
void levelOrderTraversal(int root) {
    if (root == -1) {
        return;
    }
    enqueue(root);
    while (front < rear) {
        int currentNode = dequeue();
        
        if (currentNode != -1) {
            printf("%d ", currentNode);
            if (leftChild[currentNode] != -1) {
                enqueue(leftChild[currentNode]);
            }
            if (rightChild[currentNode] != -1) {
                enqueue(rightChild[currentNode]);
            }
        }
    }
    printf("\n");
}
int main() {
    int n, root;
    for (int i = 0; i < MAX_SIZE; i++) {
        leftChild[i] = -1;
        rightChild[i] = -1;
    }
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("The tree is empty\n");
        return 0;
    }
    printf("Enter the root node: ");
    scanf("%d", &root);
    printf("Enter the child nodes in the format: node leftChild rightChild (-1 if no child):\n");
    for (int i = 0; i < n; i++) {
        int node, left, right;
        scanf("%d %d %d", &node, &left, &right);
        if (node >= 0 && node < MAX_SIZE) {
            leftChild[node] = left;
            rightChild[node] = right;
        }
    }
    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    return 0;
}
