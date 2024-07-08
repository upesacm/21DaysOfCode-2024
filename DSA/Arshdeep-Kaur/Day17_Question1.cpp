#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return NULL;
    }
    
    // If both p and q are smaller than root, then LCA lies in left subtree
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // If both p and q are greater than root, then LCA lies in right subtree
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    
    // If one node is smaller and the other is larger, we have found the LCA
    return root;
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* p = root->left->left;  // Node 5
    TreeNode* q = root->right;       // Node 30

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != NULL) {
        std::cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found" << std::endl;
    }

    return 0;
}
