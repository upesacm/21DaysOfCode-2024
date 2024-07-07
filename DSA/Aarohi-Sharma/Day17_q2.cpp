#include <iostream>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val); 
        }
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } 
        else {
            root->left = insertIntoBST(root->left, val);
        }
        return root;
    }
};
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left); 
        cout << root->val << " "; 
        inorderTraversal(root->right); 
    }
}
int main() {
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    cout << "Inorder traversal of the original BST: ";
    inorderTraversal(root);
    cout << endl;
    int val = 5;
    root = solution.insertIntoBST(root, val);
    cout << "Inorder traversal of the BST after inserting " << val << ": ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
