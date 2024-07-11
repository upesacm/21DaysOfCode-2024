# include<bits/stdc++.h>
using namespace std;

typedef struct node{
    node* next;
    int data;
}node;

void insertAtBegin(node* &head ,int data){
    node * temp;
    temp=(node *)(malloc(sizeof(node)));
    temp->data=data;
    temp->next=head;
    head=temp;
}

void insertAtEnd(node* &head ,int data){
    node* ptr = head;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = nullptr;
    
    if (head == nullptr) {
        head = temp;
        return;
    }
    
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void display(node* head){
    if(head==nullptr){
        cout << "Empty\n";
    }
    else{
        node* ptr;
        ptr=head;
        while(ptr!=nullptr){
            cout << ptr->data << " ";
            ptr=ptr->next;
        }
        printf("\n");
    }
}

bool checkIdentical(node* head1, node* head2){
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == nullptr && head2 == nullptr);
}

int main(){
    node* head1 = nullptr;
    node* head2 = nullptr;
    insertAtBegin(head1, 1);
    insertAtEnd(head1, 3);
    insertAtBegin(head1, 2);
    display(head1);
    
    insertAtBegin(head2, 1);
    insertAtEnd(head2, 3);
    insertAtBegin(head2, 2);
    display(head2);

    cout << "\nChecking if lists are identical: ";
    if (checkIdentical(head1, head2)) {
        cout << "identical.\n";
    } 
    else {
        cout << "not identical.\n";
    }
    return 0;
}