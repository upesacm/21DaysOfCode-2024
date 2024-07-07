#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


vector<int> levelOrderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        result.push_back(current->val);

        if (current->left
