#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNewNode(int newValue) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = newValue;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* addValue(TreeNode* rootNode, int newValue) {
    if (rootNode == NULL) {
        return createNewNode(newValue);
    }

    if (newValue < rootNode->value) {
        rootNode->left = addValue(rootNode->left, newValue);
    } else if (newValue > rootNode->value) {
        rootNode->right = addValue(rootNode->right, newValue);
    }

    return rootNode;
}

void printTree(TreeNode* rootNode) {
    if (rootNode!= NULL) {
        printTree(rootNode->left);
        printf("%d ", rootNode->value);
        printTree(rootNode->right);
    }
}

int main() {
    TreeNode* treeRoot = createNewNode(4);
    treeRoot->left = createNewNode(2);
    treeRoot->right = createNewNode(7);
    treeRoot->left->left = createNewNode(1);
    treeRoot->left->right = createNewNode(3);

    printf("Original Tree: ");
    printTree(treeRoot);
    printf("\n");

    treeRoot = addValue(treeRoot, 5);

    printf("Updated Tree: ");
    printTree(treeRoot);
    printf("\n");

    return 0;
}
