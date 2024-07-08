// Question 1: Given a binary search tree (BST) and two nodes, find their lowest common ancestor (LCA).
// Inputs:
// The root node of the BST. Two nodes for which the LCA is to be found.
// Output:
// The value of the LCA node.

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

struct node* LCA(struct node* root, struct node* n1, struct node* n2)
{
    if (root == NULL) return NULL;
    if (root->data > n1->data && root->data > n2->data)
        return LCA(root->left, n1, n2);
    if (root->data < n1->data && root->data < n2->data)
        return LCA(root->right, n1, n2);
    return root;
}

int main()
{
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
 
    struct node *n1 = root->left->right->left;
    struct node *n2 = root->right;
    struct node *t = LCA(root, n1, n2);
    cout << "LCA of " << n1->data << " and " << n2->data << " is " << t->data;
    return 0;
}