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

Node* findLCA(Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > n1 && root->data > n2) {
        return findLCA(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2) {
        return findLCA(root->right, n1, n2);
    }
    return root;
}

void findAndPrintLCA(Node* root, int n1, int n2) {
    Node* lca = findLCA(root, n1, n2);
    if (lca!= NULL) {
        printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
    } else {
        printf("Keys are not present\n");
    }
}

int main() {
    Node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    root->right->left = createNode(25);
    root->right->right = createNode(35);

    int n1 = 5, n2 = 30;
    findAndPrintLCA(root, n1, n2);

    return 0;
}
