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

    void createCycle(int pos) {
        if (head == nullptr) return;
        Node* cycleNode = head;
        Node* lastNode = head;
        int count = 0;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
            if (count < pos) {
                cycleNode = cycleNode->next;
                count++;
            }
        }
        lastNode->next = cycleNode;
    }
};

string detectCycle(Node* head) {
    if (head == nullptr) return "no cycle";

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return "cycle";
        }
    }
    return "no cycle";
}

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    list.createCycle(1); // Creating a cycle at position 1 (0-based index)

    cout << "Cycle Detection: " << detectCycle(list.getHead()) << endl;

    return 0;
}
