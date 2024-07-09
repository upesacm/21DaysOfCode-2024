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

void printInOrder(int node) {
    if (node == -1) {
        return;
    }
    printInOrder(leftChild[node]);
    printf("%d ", values[node]);
    printInOrder(rightChild[node]);
}

int main() {
    int n, rootValue, valueToInsert;
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

    printf("Enter the value to be inserted: ");
    scanf("%d", &valueToInsert);

    insertNode(0, valueToInsert);

    printf("In-order traversal of the updated BST: ");
    printInOrder(0);
    printf("\n");

    return 0;
}
