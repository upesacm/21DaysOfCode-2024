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
    node->left = node->right = NULL;
    return node;
}


int height(struct Node* node) {
    if (node == NULL) {
        return -1; 
    }
    

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}


int main() {
    struct Node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->right->left = newNode(4);
    root->right->right = newNode(6);
    
    printf("Height of the binary tree is: %d\n", height(root));
    
    return 0;
}
