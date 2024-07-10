#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int key) : data(key), left(nullptr), right(nullptr) {}
};

vector<int> topView(TreeNode* root) {
    if (root == nullptr) {
        return {};
    }

    
    map<int, int> topViewMap;
    
    queue<pair<TreeNode*, int>> q;

    
    q.push({root, 0});

    while (!q.empty()) {
        auto node_pair = q.front();
        q.pop();

        TreeNode* node = node_pair.first;
        int hd = node_pair.second;

        
        if (topViewMap.find(hd) == topViewMap.end()) {
            topViewMap[hd] = node->data;
        }

        
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    
    vector<int> topViewList;
    for (auto it : topViewMap) {
        topViewList.push_back(it.second);
    }

    return topViewList;
}

int main() {
        
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = topView(root);
    for (int val : result) {
        cout << val << " ";
    }
    // Output: 4 2 1 3 7

    

    return 0;
}
