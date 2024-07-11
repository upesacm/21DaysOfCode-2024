#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }

    // Function to reverse the linked list
    void reverse() {
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Function to print the linked list
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to push elements at the back
    void pushBack(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
};

int main() {
    LinkedList ll;
    ll.pushBack(1);
    ll.pushBack(2);
    ll.pushBack(3);

    cout << "Original linked list\n";
    ll.print();

    ll.reverse();

    cout << "\nReversed linked list\n";
    ll.print();

    return 0;
}
