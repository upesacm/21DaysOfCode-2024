#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define OFFSET 50  // Offset to handle negative indices

int leftChild[MAX_SIZE];
int rightChild[MAX_SIZE];
int values[MAX_SIZE];
int queue[MAX_SIZE];
int horizontalDistance[MAX_SIZE];
int topView[MAX_SIZE];
int front = 0, rear = 0;

void enqueue(int node, int hd) {
    if (rear < MAX_SIZE) {
        queue[rear] = node;
        horizontalDistance[rear++] = hd;
    }
}

int dequeue() {
    if (front < rear) {
        return front++;
    }
    return -1;
}

void topViewTraversal(int root) {
    if (root == -1) {
        return;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        topView[i] = -1;
    }

    enqueue(root, 0);

    while (front < rear) {
        int index = dequeue();
        int currentNode = queue[index];
        int hd = horizontalDistance[index] + OFFSET;

        if (topView[hd] == -1) {
            topView[hd] = values[currentNode];
        }

        if (leftChild[currentNode] != -1) {
            enqueue(leftChild[currentNode], hd - 1 - OFFSET);
        }

        if (rightChild[currentNode] != -1) {
            enqueue(rightChild[currentNode], hd + 1 - OFFSET);
        }
    }
}

int main() {
    int n, rootValue;
    for (int i = 0; i < MAX_SIZE; i++) {
        leftChild[i] = -1;
        rightChild[i] = -1;
        values[i] = 0;
    }

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The binary tree is empty\n");
        return 0;
    }

    printf("Enter the value of the root node: ");
    scanf("%d", &rootValue);

   
    values[0] = rootValue;

    printf("Enter the values of the other nodes in the format: node leftChild rightChild (-1 if no child):\n");
    for (int i = 1; i < n; i++) {
        int node, left, right;
        scanf("%d %d %d", &node, &left, &right);
        if (node >= 0 && node < MAX_SIZE) {
            if (left != -1) {
                leftChild[node] = i;
                values[i] = left;
            }
            if (right != -1) {
                rightChild[node] = i + n;
                values[i + n] = right;
            }
        }
    }

    topViewTraversal(0);

    printf("Top view of the binary tree: ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (topView[i] != -1) {
            printf("%d ", topView[i]);
        }
    }
    printf("\n");

    return 0;
}
