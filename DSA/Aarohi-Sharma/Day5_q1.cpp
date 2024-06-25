#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int value;
    Node*next;
    Node*prev;
};
int main() {
    Node* head;
    Node* one = new Node();
    Node* two = new Node();
    Node* three = new Node();
    one->value = 1;
    two->value = 2;
    three->value = 3;
    one->next = two;
    two->next = three;
    three->next = NULL;
    three->prev=two;
    two->prev=one;
    one->prev=NULL;
    head = one;
    while (head->next!=NULL) {
        head=head->next;
    }
    while (head!=NULL){
        cout<<head->value<<endl;
        head=head->prev;
    }
}
