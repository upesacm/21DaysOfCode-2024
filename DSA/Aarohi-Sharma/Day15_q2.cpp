#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int data;
    node* left;
    node* right;
}node;
node* NewNode(int data){
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int height(node* root){
    if (root == NULL)
        return 0;
    else {
        int lDepth = height(root->left);
        int rDepth = height(root->right);
        if (lDepth > rDepth)
            return (lDepth+1);
        else
            return (rDepth+1);
    }
}
void printCurrLevel(node* root,int level){
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1){
        printCurrLevel(root->left, level-1);
        printCurrLevel(root->right, level-1);
    }
}
void printLevelOrder(node* root){
    int h = height(root);
    for (int i = 1; i <= h; i++)
        printCurrLevel(root, i);
}
int main(){
    node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    printLevelOrder(root);
    return 0;
}
