#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int leftChild[MAX_SIZE];
int rightChild[MAX_SIZE];
int values[MAX_SIZE];

void insertNode(int root, int value) {
    if (value < values[root]) {
        if (leftChild[root] == -1) {
            for (int i = 0; i < MAX_SIZE; i++) {
                if (values[i] == 0) {
                    values[i] = value;
                    leftChild[root] = i;
                    break;
                }
            }
        } else {
            insertNode(leftChild[root], value);
        }
    } else {
        if (rightChild[root] == -1) {
            for (int i = 0; i < MAX_SIZE; i++) {
                if (values[i] == 0) {
                    values[i] = value;
                    rightChild[root] = i;
                    break;
                }
            }
        } else {
            insertNode(rightChild[root], value);
        }
    }
}

int findLCA(int root, int n1, int n2) {
    if (root == -1) return -1;

    if (values[root] > n1 && values[root] > n2) {
        return findLCA(leftChild[root], n1, n2);
    }

    if (values[root] < n1 && values[root] < n2) {
        return findLCA(rightChild[root], n1, n2);
    }

    return root;
}

int main() {
    int n, rootValue, node1, node2;
    for (int i = 0; i < MAX_SIZE; i++) {
        leftChild[i] = -1;
        rightChild[i] = -1;
        values[i] = 0;
    }

    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The BST is empty\n");
        return 0;
    }

    printf("Enter the value of the root node: ");
    scanf("%d", &rootValue);
    values[0] = rootValue;

    printf("Enter the values of the other nodes:\n");
    for (int i = 1; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertNode(0, value);
    }

    printf("Enter the first node: ");
    scanf("%d", &node1);
    printf("Enter the second node: ");
    scanf("%d", &node2);

    int lcaIndex = findLCA(0, node1, node2);
    if (lcaIndex != -1) {
        printf("The LCA of %d and %d is %d\n", node1, node2, values[lcaIndex]);
    } else {
        printf("LCA not found\n");
    }

    return 0;
}
