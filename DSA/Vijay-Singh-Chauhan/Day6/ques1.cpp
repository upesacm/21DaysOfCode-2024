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

node *insert(node *head,int x){
    if(x<=0){
        return NULL;
    }
    node *current=head;
    int val;
     if (current == NULL) {
        head = new node(val);
        current = head;
    }
    
    
     for(int i=1;i<=x;i++){
        cout<<"Enter value of node";
        cin>>val;
        node *temp=new node(x);
        current->next=temp;
        current=temp;
     }

    int cyclepos;
    cout<<"Enter position:";
    cin>>cyclepos;

    if(cyclepos>0 && cyclepos<=x){
        node *cyclenode=head;
        for(int i=1;i<cyclepos;i++){
            cyclenode=cyclenode->next;
        }
        current->next=cyclenode;
    }
    return head;
}
void print(node *head){
    node *current=head;
    if(current==NULL){
        return ;
    }
    cout<<current->data<<"->";
    print(current->next);
}
bool detectcycle(node *head) {
    if (head == NULL) return false;

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}
 
 
 
int main(){
    int size;
    cout<<"Enter Size of linked list";
    cin>>size;
    node *head=NULL;
    
    head=insert(head,size);
    if(detectcycle(head)){
        cout<<"cycle";
    }
    else{
        cout<<"no cycle";
    }


    return 0;
}
