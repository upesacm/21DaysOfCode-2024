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
};

int getLength(Node* head) {
    int length = 0;
    while (head != nullptr) {
        head = head->next;
        length++;
    }
    return length;
}

int findMergePoint(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* longer = len1 > len2 ? head1 : head2;
    Node* shorter = len1 > len2 ? head2 : head1;

    int difference = abs(len1 - len2);
    for (int i = 0; i < difference; i++) {
        longer = longer->next;
    }

    while (longer != nullptr && shorter != nullptr) {
        if (longer == shorter) {
            return longer->data;
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    return -1; 
}

int main() {
    LinkedList list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);

    LinkedList list2;
    list2.append(4);
    list2.append(5);

  
    Node* mergeNode = list1.getHead()->next->next; 
    list2.getHead()->next->next = mergeNode;

    cout << "Merge Point: " << findMergePoint(list1.getHead(), list2.getHead()) << endl;

    return 0;
}
