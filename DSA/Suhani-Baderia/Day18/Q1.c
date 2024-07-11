#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void topView(TreeNode* root, int hd, int* min_hd, int* max_hd, int* topViewArray, int* topViewIndex) {
    if (root == NULL) {
        return;
    }

    if (hd < *min_hd) {
        *min_hd = hd;
        topViewArray[(*topViewIndex)++] = root->data;
    }

    if (hd > *max_hd) {
        *max_hd = hd;
        topViewArray[(*topViewIndex)++] = root->data;
    }

    topView(root->left, hd - 1, min_hd, max_hd, topViewArray, topViewIndex);
    topView(root->right, hd + 1, min_hd, max_hd, topViewArray, topViewIndex);
}

void printTopView(TreeNode* root) {
    int min_hd = 0, max_hd = 0;
    int topViewArray[100];
    int topViewIndex = 0;

    topView(root, 0, &min_hd, &max_hd, topViewArray, &topViewIndex);

    for (int i = 0; i < topViewIndex; i++) {
        printf("%d ", topViewArray[i]);
    }
    printf("\n");
}

int main() {
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printTopView(root);

    return 0;
}
