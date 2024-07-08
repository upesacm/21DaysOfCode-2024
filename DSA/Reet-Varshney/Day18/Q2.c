#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createTreeNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void decodeBinaryString(TreeNode* tree, char* binaryCode) {
    TreeNode* temp = tree;
    int i = 0;
    while (binaryCode[i] != '\0') {
        if (binaryCode[i] == '0') {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        i++;
        if (temp->left == NULL && temp->right == NULL) {
            printf("%c", temp->data);
            temp = tree;
        }
    }
}

int main() {
    TreeNode* tree = createTreeNode('\0');
    tree->left = createTreeNode('A');
    tree->right = createTreeNode('\0');
    tree->right->left = createTreeNode('C');
    tree->right->right = createTreeNode('B');

    char binaryCode[] = "1001011";
    printf("Decoded text: ");
    decodeBinaryString(tree, binaryCode);
    printf("\n");

    return 0;
}
