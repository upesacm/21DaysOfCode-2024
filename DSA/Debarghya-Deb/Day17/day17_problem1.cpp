#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

TreeNode* findLCA(TreeNode* root, TreeNode* node1, TreeNode* node2) {
    while (root != nullptr) {
        // If both nodes are smaller than root, LCA lies in the left subtree
        if (node1->value < root->value && node2->value < root->value) {
            root = root->left;
        }
        // If both nodes are greater than root, LCA lies in the right subtree
        else if (node1->value > root->value && node2->value > root->value) {
            root = root->right;
        }
        // If one node is on the left and the other is on the right, or one is equal to root, root is the LCA
        else {
            return root;
        }
    }
    return nullptr; 
}

int main() {
    
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* node1 = root->left; 
    TreeNode* node2 = root->right;

    TreeNode* lca = findLCA(root, node1, node2);
    
    if (lca != nullptr) {
        std::cout << "Lowest Common Ancestor of " << node1->value << " and " << node2->value << " is " << lca->value << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    

    return 0;
}
