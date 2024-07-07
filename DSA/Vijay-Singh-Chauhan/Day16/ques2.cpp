#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* createtree(){
    int data;
    cout<<"Enter value: "<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    Node* root=new Node(data);
    
    cout<<"left child for "<<root->data<<" ";
    root->left=createtree();

    cout<<"right child for "<<root->data<<" ";
    root->right=createtree();
}

void inordertree(Node* root){
    if(root==NULL){
        return;
    }
    inordertree(root->left);
    cout<<root->data<<" ";
    inordertree(root->right);

}
int main(){
    Node* root=createtree();
    inordertree(root);
}
