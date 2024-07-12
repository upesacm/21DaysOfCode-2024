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
    Node* newNode = new Node(data);
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  return head;
}

int main() {
  cout << "Create first linked list" << endl;
  Node* head1 = createList();
  cout << "Create second linked list" << endl;
  Node* head2 = createList();

  if (head1 && head1->next && head1->next->next) {
    Node* temp = head2;
    while (temp && temp->next) {
      temp = temp->next;
    }
    if (temp) {
      temp->next = head1->next->next; 
    }
  }

  Node* mergePoint = findMergePoint(head1, head2);
  if (mergePoint != nullptr) {
    cout << "Merge Point: " << mergePoint->data << endl;
  } else {
    cout << "No merge point found." << endl;
  }

  return 0;
}
