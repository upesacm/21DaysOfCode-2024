#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;

TreeNode* createTreeNode(int value) {
    TreeNode* newNodePtr = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNodePtr) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNodePtr->value = value;
    newNodePtr->leftChild = newNodePtr->rightChild = NULL;
    return newNodePtr;
}

void traverseInOrder(TreeNode* currentNode) {
    if (currentNode == NULL) {
        return;
    }
    traverseInOrder(currentNode->leftChild);
    printf("%d ", currentNode->value);
    traverseInOrder(currentNode->rightChild);
}

int main() {
    TreeNode* treeRoot = createTreeNode(1);
    treeRoot->leftChild = createTreeNode(2);
    treeRoot->rightChild = createTreeNode(3);
    treeRoot->leftChild->leftChild = createTreeNode(4);
    treeRoot->leftChild->rightChild = createTreeNode(5);

    printf("Tree Values in Order: ");
    traverseInOrder(treeRoot);
    printf("\n");

    return 0;
}
