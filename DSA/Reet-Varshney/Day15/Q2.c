#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;

void breadthFirstTraversal(TreeNode* rootNode) {
    if (rootNode == NULL) {
        return;
    }

    TreeNode* nodeQueue[100];
    int frontIndex = 0, rearIndex = 0;
    nodeQueue[rearIndex++] = rootNode;

    while (frontIndex < rearIndex) {
        TreeNode* currentNode = nodeQueue[frontIndex++];
        printf("%d ", currentNode->value);

        if (currentNode->leftChild != NULL) {
            nodeQueue[rearIndex++] = currentNode->leftChild;
        }
        if (currentNode->rightChild != NULL) {
            nodeQueue[rearIndex++] = currentNode->rightChild;
        }
    }
    printf("\n");
}

int main() {
    TreeNode* rootNode = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->value = 3;
    rootNode->leftChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->rightChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->leftChild->value = 9;
    rootNode->rightChild->value = 20;
    rootNode->leftChild->leftChild = NULL;
    rootNode->leftChild->rightChild = NULL;
    rootNode->rightChild->leftChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->rightChild->rightChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->rightChild->leftChild->value = 15;
    rootNode->rightChild->rightChild->value = 7;
    rootNode->rightChild->leftChild->leftChild = NULL;
    rootNode->rightChild->leftChild->rightChild = NULL;
    rootNode->rightChild->rightChild->leftChild = NULL;
    rootNode->rightChild->rightChild->rightChild = NULL;

    breadthFirstTraversal(rootNode);

    return 0;
}
