#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int value;
    Node* next;
};
bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        if (s.find(h) != s.end())
            return true;
        s.insert(h);
        h = h->next;
    }
    return false;
}
int main() {
    Node* head1;
    Node* one1 = new Node();
    Node* two1 = new Node();
    Node* three1 = new Node();
    Node* four1=new Node();
    Node* five1=new Node();
    one1->value = 1;
    two1->value = 2;
    three1->value = 3;
    four1->value=4;
    five1->value=2;
    one1->next = two1;
    two1->next = three1;
    three1->next = four1;
    four1->next=five1;
    five1->next=NULL;
    head1 = one1;
    if(detectLoop(head1)){
        cout<<"cycle";
    }
    else{
        cout<<"no cycle";
    }
}
