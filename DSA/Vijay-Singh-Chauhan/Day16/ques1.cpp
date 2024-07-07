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

Node* createnode(){
    int data;
    cout<<"Enter value "<<endl;
    cin>>data;

    if(data==0){
        return NULL;
    }

    Node* root=new Node(data);

    cout<<"left node for "<<root->data<<endl;
    root->left=createnode();

    cout<<"right node for "<<root->data<<endl;
    root->right=createnode();

    return root;
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}
int main(){
    cout<<"Enter 0 for empty node"<<endl;
    Node* root=createnode();

    
    cout<<"post order tree: ";
    postorder(root);
}
