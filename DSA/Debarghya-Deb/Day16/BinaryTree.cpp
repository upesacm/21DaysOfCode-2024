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



void inorderTraversal(Node* root){
    //base case
    Node* temp = root;

    if(temp  == NULL){
        return;
    }

    inorderTraversal(temp -> left);
    cout<<temp-> data << endl;
    inorderTraversal(temp-> right);
    return;
}


void postOrdertraversal(Node* root){
    Node* temp = root;
    if(temp  == NULL){
        return;
    }
    
    

    postOrdertraversal(temp -> left);
        
    postOrdertraversal(temp-> right);
    cout<<temp-> data << endl;
    return;
}



int main(){
    
    Node* root = NULL;
    root = BuildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17  -1 -1 -1
    
    
    cout<<"IN ORDER TRAVERSAL : "<<endl;
    inorderTraversal(root);
    
    cout<<"Post ORDER TRAVERSAL : "<<endl;
    postOrdertraversal(root);
    return 0;
}