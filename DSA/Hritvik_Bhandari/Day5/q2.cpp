#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Function to compare two linked lists
    bool compareLists(const LinkedList& other) const {
        Node* current1 = head;
        Node* current2 = other.head;

        while (current1 != nullptr && current2 != nullptr) {
            if (current1->data != current2->data) {
                return false; // Data mismatch
            }
            current1 = current1->next;
            current2 = current2->next;
        }

        // Both should reach the end at the same time
        return (current1 == nullptr && current2 == nullptr);
    }

    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list1;
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);

    LinkedList list2;
    list2.insertAtEnd(10);
    list2.insertAtEnd(20);
    list2.insertAtEnd(30);

    LinkedList list3;
    list3.insertAtEnd(10);
    list3.insertAtEnd(25);
    list3.insertAtEnd(30);

    cout << "List 1: ";
    list1.printList();
    cout << "List 2: ";
    list2.printList();
    cout << "List 3: ";
    list3.printList();

    cout << "Comparing list1 and list2: ";
    if (list1.compareLists(list2)) {
        cout << "Identical" << endl;
    } else {
        cout << "Not identical" << endl;
    }

    cout << "Comparing list1 and list3: ";
    if (list1.compareLists(list3)) {
        cout << "Identical" << endl;
    } else {
        cout << "Not identical" << endl;
    }

    return 0;
}
