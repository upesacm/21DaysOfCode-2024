#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;

TreeNode* createTreeNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->leftChild = newNode->rightChild = NULL;
    return newNode;
}

TreeNode* findCommonAncestor(TreeNode* rootNode, int val1, int val2) {
    if (rootNode == NULL) {
        return NULL;
    }

    if (rootNode->value > val1 && rootNode->value > val2) {
        return findCommonAncestor(rootNode->leftChild, val1, val2);
    }

    if (rootNode->value < val1 && rootNode->value < val2) {
        return findCommonAncestor(rootNode->rightChild, val1, val2);
    }

    return rootNode;
}

void printAncestorValue(TreeNode* rootNode, int val1, int val2) {
    TreeNode* ancestor = findCommonAncestor(rootNode, val1, val2);
    if (ancestor != NULL) {
        printf("The common node of %d and %d is %d\n", val1, val2, ancestor->value);
    } else {
        printf("Common ancestor not found\n");
    }
}

int main() {
    TreeNode* treeRoot = createTreeNode(20);
    treeRoot->leftChild = createTreeNode(10);
    treeRoot->rightChild = createTreeNode(30);
    treeRoot->leftChild->leftChild = createTreeNode(5);
    treeRoot->leftChild->rightChild = createTreeNode(15);
    treeRoot->rightChild->leftChild = createTreeNode(25);
    treeRoot->rightChild->rightChild = createTreeNode(35);

    printAncestorValue(treeRoot, 10, 25);

    return 0;
}
