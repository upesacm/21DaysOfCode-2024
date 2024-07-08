#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;

int treeHeight(TreeNode* rootNode) {
    if (rootNode == NULL) {
        return 0;
    } else {
        int leftHeight = treeHeight(rootNode->leftChild);
        int rightHeight = treeHeight(rootNode->rightChild);
        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        } else {
            return rightHeight + 1;
        }
    }
}

int main() {
    TreeNode* rootNode = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->value = 3;
    rootNode->leftChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->rightChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->leftChild->value = 2;
    rootNode->rightChild->value = 5;
    rootNode->leftChild->leftChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->rightChild->leftChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->rightChild->rightChild = (TreeNode*)malloc(sizeof(TreeNode));
    rootNode->leftChild->leftChild->value = 1;
    rootNode->rightChild->leftChild->value = 4;
    rootNode->rightChild->rightChild->value = 6;
    rootNode->leftChild->leftChild->leftChild = NULL;
    rootNode->leftChild->leftChild->rightChild = NULL;
    rootNode->rightChild->leftChild->leftChild = NULL;
    rootNode->rightChild->leftChild->rightChild = NULL;
    rootNode->rightChild->rightChild->leftChild = NULL;
    rootNode->rightChild->rightChild->rightChild = NULL;

    int heightOfTree = treeHeight(rootNode);
    printf("The height of the binary tree is: %d\n", heightOfTree);

    return 0;
}
