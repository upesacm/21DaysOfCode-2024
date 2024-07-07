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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);
    Solution solution;
    TreeNode* p = root->left->left;  
    TreeNode* q = root->right; 
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "The LCA of nodes " << p->val << " and " << q->val << " is " << lca->val << endl;
    } else {
        cout << "LCA not found." << endl;
    }
    return 0;
}
