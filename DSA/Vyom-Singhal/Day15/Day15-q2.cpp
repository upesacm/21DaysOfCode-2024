#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void levelOrderTraversal(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}
