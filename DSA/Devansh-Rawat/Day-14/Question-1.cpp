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
int main(){
    node* root = NewNode(1);
    root->left = NewNode(2);
    root->right = NewNode(3);
    root->left->left = NewNode(4);
    root->left->right = NewNode(5);
    cout << height(root)-1 << endl;
    return 0;
}
