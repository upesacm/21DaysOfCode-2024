#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return nullptr;
    }

    if (p->data < root->data && q->data < root->data) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (p->data > root->data && q->data > root->data) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* p = root->left->left; 
    TreeNode* q = root->right;      

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "The lowest common ancestor of nodes " << p->data << " and " << q->data << " is: " << lca->data << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
