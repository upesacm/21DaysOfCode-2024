#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int findHeight(TreeNode* root) {
    if (root == NULL) {
        return -1; 
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

   
    return max(leftHeight, rightHeight) + 1;
}


int main() {
   
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int height = findHeight(root);
    cout << "Height of the binary tree: " << height << endl;

    return 0;
}
