#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void topView(Node* root, int* min, int* max, int hd, int* topViewArray, int* topViewIndex) {
    if (root == NULL) return;

    if (hd < *min) {
        *min = hd;
        topViewArray[(*topViewIndex)++] = root->data;
    }

    if (hd > *max) {
        *max = hd;
        topViewArray[(*topViewIndex)++] = root->data;
    }

    topView(root->left, min, max, hd - 1, topViewArray, topViewIndex);
    topView(root->right, min, max, hd + 1, topViewArray, topViewIndex);
}
void getTopView(Node* root) {
    int min = 0, max = 0;
    int topViewArray[100]; 
    int topViewIndex = 0;

    topView(root, &min, &max, 0, topViewArray, &topViewIndex);

    for (int i = 0; i < topViewIndex; i++) {
        printf("%d ", topViewArray[i]);
    }
    printf("\n");
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    getTopView(root);

    return 0;
}
