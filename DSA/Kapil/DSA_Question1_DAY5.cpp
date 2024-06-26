#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void printReverse(Node* head) {
    if (head == nullptr) {
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Print the linked list in reverse
    printReverse(head);
    cout << endl;

    // Free the allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
