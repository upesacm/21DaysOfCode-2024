#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* newNode(int value) {
    Node* nodePtr = (Node*)malloc(sizeof(Node));
    if (!nodePtr) {
        printf("Memory error\n");
        return NULL;
    }
    nodePtr->value = value;
    nodePtr->leftChild = nodePtr->rightChild = NULL;
    return nodePtr;
}

void traverseTree(Node* currentNode) {
    if (currentNode == NULL) {
        return;
    }
    traverseTree(currentNode->leftChild);
    traverseTree(currentNode->rightChild);
    printf("%d ", currentNode->value);
}

int main() {
    Node* treeRoot = newNode(1);
    treeRoot->leftChild = newNode(2);
    treeRoot->rightChild = newNode(3);
    treeRoot->leftChild->leftChild = newNode(4);
    treeRoot->leftChild->rightChild = newNode(5);

    printf("Tree Traversal: ");
    traverseTree(treeRoot);
    printf("\n");

    return 0;
}
