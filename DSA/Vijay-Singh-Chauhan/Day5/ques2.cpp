#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};

node* insertend(node *head, int x){
    node *temp=new node(x);
    if(head==NULL){
        return temp;
    }
    node *current=head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next = temp;
    return head;

}

bool areidentical(node* a, node*b){
    if(a==NULL && b==NULL){
        return true;
    }
    if(a!=NULL && b!=NULL){
        return (a->data == b->data) && areidentical(a->next,b->next);
    }
    return false;
}
int main(){
     int nodes,x;
    cout<<"Enter number of nodes:";
    cin>>nodes;
    node *a=NULL;
    node *b=NULL;

    for(int i=0;i<nodes;i++){
        cin>>x;
        a=insertend(a,x);
    }
    
    for(int i=0;i<nodes;i++){
        cin>>x;
        b=insertend(b,x);
    }
    if(areidentical(a,b)){
        cout<<"Identical";
    }
    else{
        cout<<"Not Identical";
    }

}
