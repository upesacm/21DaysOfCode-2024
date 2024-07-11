#include<iostream>
 #include<queue>
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
    cout<<"Enter Value: "<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    Node* root=new Node(data);

    cout<<"left child of "<<root->data<<endl;
    root->left=createtree();

    cout<<"right child of "<<root->data<<endl;
    root->right=createtree();
 }

 void levelorder(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
  
    while(q.size()>1){
        Node* front=q.front();
        q.pop();

        if(front==NULL){
            cout<<endl;
            q.push(NULL); 
        }

        else{
            cout<<front->data<<" ";

            if(front->left!=NULL){
               q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
 }
 int main(){
    Node* root=createtree();

    cout<<"Level-order trversal tree"<<endl;
    levelorder(root);
 }
