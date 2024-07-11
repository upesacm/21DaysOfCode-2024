#include<iostream>
#include<unordered_set>
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
        temp->next = head;
    }
    void printList(Node* head) {
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
    string hasCycle(Node *head) {
        unordered_set<Node*> nodesTracker;
        while(head != NULL) {
            if(nodesTracker.find(head) != nodesTracker.end()) return "cycle";
            nodesTracker.insert(head);
            head = head->next;
        }
        return "no cycle";
    }
};

int main() {
    Node* head = new Node();
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    head->createList(head,n);
    cout << head->hasCycle(head);
}
