#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int leftChild[MAX_SIZE];
int rightChild[MAX_SIZE];

int height(int node) {
    if (node == -1) {
        return -1; 
    }
    int leftHeight = height(leftChild[node]);
    int rightHeight = height(rightChild[node]);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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
        printf("The height of the tree is -1\n");
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

    printf("The height of the tree is %d\n", height(root));

    return 0;
}
