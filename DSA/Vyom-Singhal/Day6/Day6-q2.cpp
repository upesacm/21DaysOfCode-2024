#include <iostream>
using namespace std;

class Node {
    public :
        int data;
        Node* next;
    Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    }
    void insertNode(Node** head, int data) {
        Node* newNode = createNode(data);
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node* temp = *head;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    int length(Node* head) {
        int len = 0;
        while (head!= NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    int findMergePoint(Node* head1, Node* head2) {
        int len1 = length(head1);
        int len2 = length(head2);
        if (len1 > len2) {
            for (int i = 0; i < len1 - len2; i++) {
                head1 = head1->next;
            }
        } else {
            for (int i = 0; i < len2 - len1; i++) {
                head2 = head2->next;
            }
        }
        while (head1!= head2) {
            head1 = head1->next;
            head2 = head2->next;
        }
        return head1->data;
    }
};

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n1, n2;
    cout << "Enter the number of nodes in the first linked list: ";
    cin >> n1;
    cout << "Enter the data for the first linked list: ";
    for (int i = 0; i < n1; i++) {
        int data;
        cin >> data;
        head1->insertNode(&head1, data);
    }
    cout << "Enter the number of nodes in the second linked list: ";
    cin >> n2;
    cout << "Enter the data for the second linked list: ";
    for (int i = 0; i < n2; i++) {
        int data;
        cin >> data;
        head2->insertNode(&head2, data);
    }
    Node* temp1 = head1;
    while (temp1->next!= NULL) {
        temp1 = temp1->next;
    }
    Node* temp2 = head2;
    while (temp2->next!= NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp1->next;
    cout << "Merge point: " << head1->findMergePoint(head1, head2) << endl;
}