#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    int lH = height(root->left);
    int rH = height(root->right);
    return (lH > rH ? lH : rH) + 1;
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->right->left = newNode(4);
    root->right->right = newNode(6);

    printf("The height of the tree is: %d\n", height(root));

    return 0;
}
