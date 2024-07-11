#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int value;
    Node* next;
};
bool check(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->value != head2->value) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}
int main() {
    Node* head1;
    Node* one1 = new Node();
    Node* two1 = new Node();
    Node* three1 = new Node();
    one1->value = 1;
    two1->value = 2;
    three1->value = 3;
    one1->next = two1;
    two1->next = three1;
    three1->next = NULL;
    head1 = one1;
    Node* head2;
    Node* one2 = new Node();
    Node* two2 = new Node();
    Node* three2 = new Node();
    one2->value = 1;
    two2->value = 2;
    three2->value = 3;
    one2->next = two2;
    two2->next = three2;
    three2->next = NULL;
    head2 = one2;
    if (check(head1, head2)) {
        cout << "Identical" << endl;
    } else {
        cout << "Not identical" << endl;
    }
    return 0;
}
