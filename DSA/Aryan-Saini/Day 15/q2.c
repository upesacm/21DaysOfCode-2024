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
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* queue[100]; 
    int front = 0, rear = 0;


    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];


        printf("%d ", current->data);


        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

 
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Level order traversal of the binary tree is: ");
    levelOrderTraversal(root);

    return 0;
}
