#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

TreeNode *insertLevelOrder(int arr[], int i, int n)
{
    if (i < n)
    {
        TreeNode *root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
        return root;
    }
    return NULL;
}

int main()
{
    int n;
    cout << "Enter the number of elements in the binary tree: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the binary tree (use -1 for NULL nodes): ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    TreeNode *root = insertLevelOrder(arr, 0, n);

    cout << "Height of the tree: " << height(root) << endl;

    return 0;
}
