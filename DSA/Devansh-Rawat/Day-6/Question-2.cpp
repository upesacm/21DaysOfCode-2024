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

Node* findMergePoint(Node* head1, Node* head2) {
  if (head1 == nullptr || head2 == nullptr) {
    return nullptr;
  }

  Node* pointer1 = head1;
  Node* pointer2 = head2;

  while (pointer1 != pointer2) {
    pointer1 = (pointer1 == nullptr) ? head2 : pointer1->next;
    pointer2 = (pointer2 == nullptr) ? head1 : pointer2->next;
  }

  return pointer1;
}

Node* createList() {
  Node* head = nullptr;
  Node* tail = nullptr;
  int data;

  while (true) {
    cout << "Enter data for the linked list (-1 to stop): ";
    cin >> data;
    if (data == -1) {
      break;
    }
  }