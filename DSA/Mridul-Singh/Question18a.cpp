#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node * newNode(int data){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

vector<int> topView(struct node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    map <int,int> mpp;
    queue <pair<struct node*, int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        struct node* n=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end()){
            mpp[line]=n->data;
        }
        if(n->left!=NULL){
            q.push({n->left,line-1});
        }
        if(n->right != NULL){
            q.push({n->right,line+1});
        }
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right=newNode(6);
    root->right->left=newNode(7);
    vector<int> res=topView(root);
    for(auto it:res){
        cout << it << " ";
    }
    return 0;
}