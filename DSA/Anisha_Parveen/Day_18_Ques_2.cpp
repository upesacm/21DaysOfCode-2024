#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversalHelper(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    inorderTraversalHelper(root->left, result);
    result.push_back(root->val);
    inorderTraversalHelper(root->right, result);
}

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> result;
    inorderTraversalHelper(root, result);
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> inorderResult = inorderTraversal(root);

    for (int val : inorderResult)
    {
        cout << val << " ";
    }

    return 0;
}
