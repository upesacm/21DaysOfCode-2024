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
    string compareList(Node* head1, Node* head2, int n1, int n2) {
        if(n1 != n2) return "different";
        while(head1 != NULL && head2 != NULL) {
            if(head1->data != head2->data) return "different";
            head1 = head1->next;
            head2 = head2->next;
        }
        return "identical";
    }
    void printList(Node* head) {
        while(head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
};

int main() {
    Node* head1 = new Node();
    Node* head2 = new Node();
    int n1, n2;
    cout << "Enter number of elements for list 1 : ";
    cin >> n1;
    head1->createList(head1,n1);
    cout << "Enter number of elements for list 2 : ";
    cin >> n2;
    head2->createList(head2,n2);
    cout << head1->compareList(head1,head2,n1,n2);
}