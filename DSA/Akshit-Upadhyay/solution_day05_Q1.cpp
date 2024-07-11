#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* newNode(int data) {
  Node* temp = new Node;
  temp->data = data;
  temp->next = nullptr;
  return temp;
}

void insertAtBeginning(Node** head_ref, int new_data) {
  Node* new_node = newNode(new_data);
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int getInput() {
  int num;
  cout << "Enter an integer: ";
  cin >> num;
  return num;
}

void printList(Node* node) {
  while (node != nullptr) {
    cout << node->data << " ";
    node = node->next;
  }
  cout << endl;
}

void reverseLinkedList(Node** head_ref) {
  Node* prev = nullptr;
  Node* curr = *head_ref;
  Node* next;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head_ref = prev;
}

int main() {
  Node* head = nullptr;

  int choice = 1;
  while (choice != 0) {
    int data = getInput();
    insertAtBeginning(&head, data);
    cout << "Enter 0 to stop, or any other number to continue: ";
    cin >> choice;
  }

  cout << "Created linked list: ";
  printList(head);

  reverseLinkedList(&head);

  cout << "Reversed linked list: ";
  printList(head);

  return 0;
}
