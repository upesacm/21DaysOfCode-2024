#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

int heightOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);

    int height = heightOfBinaryTree(root);

    cout << "The height of the binary tree is: " << height << endl;

    return 0;
}
