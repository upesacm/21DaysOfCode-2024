#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> levelOrder(TreeNode *root)
{
    vector<int> result;
    if (!root)
        return result;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        result.push_back(node->val);

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return result;
}

TreeNode *buildTree(const string &data)
{
    if (data.empty())
        return nullptr;

    istringstream iss(data);
    string val;
    iss >> val;

    TreeNode *root = new TreeNode(stoi(val));
    queue<TreeNode *> q;
    q.push(root);

    while (iss >> val)
    {
        TreeNode *parent = q.front();
        q.pop();

        if (val != "null")
        {
            parent->left = new TreeNode(stoi(val));
            q.push(parent->left);
        }

        if (iss >> val && val != "null")
        {
            parent->right = new TreeNode(stoi(val));
            q.push(parent->right);
        }
    }

    return root;
}

int main()
{
    string input;
    cout << "Enter the values of the nodes in level order, separated by spaces, use 'null' for no node: ";
    getline(cin, input);

    TreeNode *root = buildTree(input);
    vector<int> result = levelOrder(root);

    cout << "Level order traversal output: ";
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}
