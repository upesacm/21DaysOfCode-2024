#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> topView(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    map<int, int> topNodeMap;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();

        TreeNode *node = p.first;
        int hd = p.second;

        if (topNodeMap.find(hd) == topNodeMap.end())
        {
            topNodeMap[hd] = node->val;
        }

        if (node->left)
        {
            q.push({node->left, hd - 1});
        }

        if (node->right)
        {
            q.push({node->right, hd + 1});
        }
    }

    for (auto it : topNodeMap)
    {
        result.push_back(it.second);
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> topViewResult = topView(root);

    for (int val : topViewResult)
    {
        cout << val << " ";
    }

    return 0;
}
