#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{

public:    
    int data;
    Node* left;
    Node* right;
    Node(int x){
        this -> data = x;
        this -> left = NULL;
        this -> right = NULL;
    }
};


Node* BuildTree(Node* root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data to the left of "<<data<< " now: ";
    root->left = BuildTree(root->left);
    cout<<"Enter the data to the right of "<<data<< " now: ";
    root->right = BuildTree(root->right);

    return root;

}

void levelOrderTraversal(Node* root){
    queue<Node* > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp -> data ;
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp->right);
            }
        }
    }
}


int main(){
    
    Node* root = NULL;
    root = BuildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17  -1 -1 -1
    levelOrderTraversal(root);

    return 0;
}