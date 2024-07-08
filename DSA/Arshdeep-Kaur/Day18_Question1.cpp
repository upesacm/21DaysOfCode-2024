#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Function to find the minimum and maximum horizontal distance from the root
void findMinMax(TreeNode* root, int* min, int* max, int hd) {
    if (root == NULL) {
        return;
    }

    if (hd < *min) {
        *min = hd;
    }

    if (hd > *max) {
        *max = hd;
    }

    findMinMax(root->left, min, max, hd - 1);
    findMinMax(root->right, min, max, hd + 1);
}

//Function to fill the array of top view nodes
void fillTopView(TreeNode* root, int hd, int level, int min, vector<pair<int, int>>& topViewArray) {
    if (root == NULL) {
        return;
    }

    int index = hd - min;

    if (topViewArray[index].second == -1 || topViewArray[index].second > level) {
        topViewArray[index] = {root->val, level};
    }

    fillTopView(root->left, hd - 1, level + 1, min, topViewArray);
    fillTopView(root->right, hd + 1, level + 1, min, topViewArray);
}

vector<int> topView(TreeNode* root) {
    if (root == NULL) return {};

    int min = 0, max = 0;

    findMinMax(root, &min, &max, 0);

    int range = max - min + 1;
    vector<pair<int, int>> topViewArray(range, {-1, -1});

    fillTopView(root, 0, 0, min, topViewArray);

    vector<int> result;
    for (const auto& p : topViewArray) {
        if (p.second != -1) {
            result.push_back(p.first);
        }
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

    vector<int> top_view = topView(root);

    for (int val : top_view) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
