#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newTreeNode(int value) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertBalanced(int* values, int start, int end) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    struct TreeNode* root = newTreeNode(values[mid]);
    root->left = insertBalanced(values, start, mid - 1);
    root->right = insertBalanced(values, mid + 1, end);
    return root;
}

int height_of_binary_tree(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    } else {
        int left_height = height_of_binary_tree(root->left);
        int right_height = height_of_binary_tree(root->right);
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}

int main() {
    struct TreeNode* root = NULL;
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int* values = (int*)malloc(n * sizeof(int));

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    root = insertBalanced(values, 0, n - 1);

    printf("Height of the binary tree: %d\n", height_of_binary_tree(root));

    free(values);
    return 0;
}
