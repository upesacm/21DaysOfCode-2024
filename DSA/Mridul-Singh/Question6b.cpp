#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

Node* findMergePoint(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) return nullptr;
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while (ptr1 != ptr2) {
        if (ptr1 == nullptr) {
            ptr1 = head2;
        } else {
            ptr1 = ptr1->next;
        }
        if (ptr2 == nullptr) {
            ptr2 = head1;
        } else {
            ptr2 = ptr2->next;
        }
    }
    return ptr1;
}

int main() {
    Node* head1 = nullptr;
    insert(head1, 3);
    insert(head1, 2);
    insert(head1, 1);

    Node* head2 = nullptr;
    Node* mergeNode = head1->next->next;
    insert(head2, 5);
    insert(head2, 4);
    head2->next->next = mergeNode;

    Node* mergePoint = findMergePoint(head1, head2);
    if (mergePoint != nullptr) {
        cout << "Merge Point: " << mergePoint->data << endl;
    } else {
        cout << "No Merge Point" << endl;
    }
    return 0;
}
