#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    while (root != NULL)
    {
        if (p->val > root->val && q->val > root->val)
            root = root->right;
        else if (p->val < root->val && q->val < root->val)
            root = root->left;
        else
            return root;
    }
    return NULL;
}

TreeNode *insert(TreeNode *node, int key)
{
    if (node == NULL)
        return new TreeNode(key);
    if (key < node->val)
        node->left = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node;
}

TreeNode *search(TreeNode *root, int key)
{
    if (root == NULL || root->val == key)
        return root;
    if (root->val < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main()
{
    int n, value, node1_val, node2_val;

    cout << "Enter the number of nodes in the BST: ";
    cin >> n;

    TreeNode *root = NULL;
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = insert(root, value);
    }

    cout << "Enter the value of the first node: ";
    cin >> node1_val;
    cout << "Enter the value of the second node: ";
    cin >> node2_val;

    TreeNode *node1 = search(root, node1_val);
    TreeNode *node2 = search(root, node2_val);

    if (node1 == NULL || node2 == NULL)
    {
        cout << "One or both nodes not found in the BST" << endl;
        return 1;
    }

    TreeNode *lca = lowestCommonAncestor(root, node1, node2);
    if (lca != NULL)
        cout << "Lowest Common Ancestor of " << node1->val << " and " << node2->val << " is " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found" << endl;

    return 0;
}
