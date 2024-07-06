#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int height(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height > right_height) {
            return left_height + 1;
        } else {
            return right_height + 1;
        }
    }
}

int main() {

    Node* root = (Node*)malloc(sizeof(Node));
    root->data = 3;
    root->left = (Node*)malloc(sizeof(Node));
    root->right = (Node*)malloc(sizeof(Node));
    root->left->data = 2;
    root->right->data = 5;
    root->left->left = (Node*)malloc(sizeof(Node));
    root->right->left = (Node*)malloc(sizeof(Node));
    root->right->right = (Node*)malloc(sizeof(Node));
    root->left->left->data = 1;
    root->right->left->data = 4;
    root->right->right->data = 6;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->left = NULL;
    root->right->right->right = NULL;


    int height_of_tree = height(root);
    printf("Height of the tree: %d\n", height_of_tree);

    return 0;
}
