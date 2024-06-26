#include<iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* next;
    void createList(Node* head, int n) {
        Node *temp = new Node();
        int data;
        cout << "Enter data for element 1 : ";
        cin >> data;
        head->data = data;
        head->next = NULL;
        temp = head;
        for(int i = 1; i < n; i++) {
            Node *newNode = new Node();
            cout << "Enter data for element " << i+1 << " : ";
            cin >> data;
            newNode->data = data;
            newNode->next = NULL;
            temp->next = newNode;
            temp = newNode;
        }
    }
    void printList(Node* head) {
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
    void reverseList(Node*& head) {
        Node* current = head;
        Node* prev = head;
        Node* next = current->next;
        prev->next = NULL;
        while(next != NULL) {
            head = next;
            current = head;
            next = current->next;
            current->next = prev;
            prev = current;
        }
    }
};

int main() {
    Node* head = new Node();
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    head->createList(head,n);
    head->reverseList(head);
    head->printList(head);
}
