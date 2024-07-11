#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int x) : data(x), next(NULL) {}
};

node* insert(node* head, int x) {
    node* temp = new node(x);
    if (head == NULL) {
        return temp;
    }
    node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    return head;
}

node* reverse(node* head) {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(node* head) {
    node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int nodes, x;
    cout << "Enter number of nodes: ";
    cin >> nodes;
    node* a = NULL;

    for (int i = 0; i < nodes; i++) {
        cin >> x;
        a = insert(a, x);
    }

    cout << "Original list: ";
    printList(a);

    a = reverse(a);

    cout << "Reversed list: ";
    printList(a);

    return 0;
}
