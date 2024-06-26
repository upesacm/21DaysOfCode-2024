#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool areIdentical(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // If both lists are of the same length and both pointers are null, they are identical
    return (head1 == nullptr && head2 == nullptr);
}

int main() {
    // Creating two sample linked lists: 1 -> 2 -> 3 and 1 -> 2 -> 3
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    // Compare the linked lists
    if (areIdentical(head1, head2)) {
        cout << "identical" << endl;
    } else {
        cout << "different" << endl;
    }

    // Free the allocated memory
    Node* current;
    while (head1 != nullptr) {
        current = head1;
        head1 = head1->next;
        delete current;
    }
    while (head2 != nullptr) {
        current = head2;
        head2 = head2->next;
        delete current;
    }

    return 0;
}
