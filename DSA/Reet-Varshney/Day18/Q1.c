#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void viewFromTop(Node* root, int hd, int* min, int* max, int* array, int* index) {
    if (root == NULL) {
        return;
    }

    if (hd < *min) {
        *min = hd;
        array[(*index)++] = root->data;
    }

    if (hd > *max) {
        *max = hd;
        array[(*index)++] = root->data;
    }

    viewFromTop(root->left, hd - 1, min, max, array, index);
    viewFromTop(root->right, hd + 1, min, max, array, index);
}

void printView(Node* root) {
    int min_hd = 0, max_hd = 0;
    int viewArray[100];
    int viewIndex = 0;

    viewFromTop(root, 0, &min_hd, &max_hd, viewArray, &viewIndex);

    for (int i = 0; i < viewIndex; i++) {
        printf("%d ", viewArray[i]);
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

    printf("Top view of the binary tree: ");
    printView(root);

    return 0;
}
