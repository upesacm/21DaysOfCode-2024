#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
vector<int> topView(TreeNode* root) {
    if (root == nullptr) return {};
    map<int, int> hdNodeMap;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto p = q.front();
        TreeNode* node = p.first;
        int hd = p.second;
        q.pop();
        if (hdNodeMap.find(hd) == hdNodeMap.end()) {
            hdNodeMap[hd] = node->data;
        }
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }
    vector<int> topViewNodes;
    for (const auto& p : hdNodeMap) {
        topViewNodes.push_back(p.second);
    }
    return topViewNodes;
}
void printTopView(const vector<int>& topViewNodes) {
    for (int val : topViewNodes) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    vector<int> topViewNodes = topView(root);
    cout << "Top view of the binary tree is: ";
    printTopView(topViewNodes);
    return 0;
}