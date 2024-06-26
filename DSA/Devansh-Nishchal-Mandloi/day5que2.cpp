#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    Node* getHead() {
        return head;
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
};

string compareLists(Node* head1, Node* head2) {
    Node* current1 = head1;
    Node* current2 = head2;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->data != current2->data) {
            return "different";
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 != nullptr || current2 != nullptr) {
        return "different";
    }

    return "identical";
}

int main() {
    LinkedList list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    LinkedList list2;
    list2.append(1);
    list2.append(2);
    list2.append(3);

    cout << "Linked list 1: ";
    list1.printList();

    cout << "Linked list 2: ";
    list2.printList();

    string result = compareLists(list1.getHead(), list2.getHead());
    cout << "Output: " << result << endl;

    return 0;
}
