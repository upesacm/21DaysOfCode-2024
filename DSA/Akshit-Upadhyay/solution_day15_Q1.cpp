#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);

    int treeHeight = height(root);
    cout << "The height of the binary tree is: " << treeHeight << endl;

    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
