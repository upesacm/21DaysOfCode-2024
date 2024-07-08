#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    else {
        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);
        return max(left_height, right_height) + 1;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new T f szreeNode(5);
    int height = maxDepth(root);
    std::cout << "Height of the binary tree: " << height;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
