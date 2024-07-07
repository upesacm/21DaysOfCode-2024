// Day 18 Question 1

#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> topView(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    map<int, int> topViewMap; 
    queue<pair<TreeNode*, int>> q; 
    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->data;
        }

        if (node->left != nullptr) {
            q.push({node->left, hd - 1});
        }

        if (node->right != nullptr) {
            q.push({node->right, hd + 1});
        }
    }

    for (auto it : topViewMap) {
        result.push_back(it.second);
    }

    return result;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> topViewResult = topView(root);
    cout << "Top view of the binary tree: ";
    for (int val : topViewResult) {
        cout << val << " ";
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}