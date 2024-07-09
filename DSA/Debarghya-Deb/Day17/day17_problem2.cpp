#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        // If the tree is empty, create a new node and return it
        return new TreeNode(val);
    }

    if (val < root->value) {
        // Insert in the left subtree
        root->left = insertIntoBST(root->left, val);
    } else {
        // Insert in the right subtree
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Create a sample BST
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    int valToInsert = 12;
    root = insertIntoBST(root, valToInsert);

    
    inorderTraversal(root);
    std::cout << std::endl;

    
    return 0;
}
