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

int getInput() {
  int num;
  cout << "Enter an integer: ";
  cin >> num;
  return num;
}

Node* createList() {
  Node* head = nullptr;
  int choice = 1;
  while (choice != 0) {
    int data = getInput();
    Node* new_node = newNode(data);
    if (head == nullptr) {
      head = new_node;
    } else {
      new_node->next = head;
      head = new_node;
    }
    cout << "Enter 0 to stop, or any other number to continue: ";
    cin >> choice;
  }
  return head;
}

bool areIdentical(Node* head1, Node* head2) {
  while (head1 && head2) {
    if (head1->data != head2->data) {
      return false;
    }
    head1 = head1->next;
    head2 = head2->next;
  }

  return head1 == head2;
}

int main() {
  Node* head1 = createList();
  cout << "Created first linked list." << endl;

  Node* head2 = createList();
  cout << "Created second linked list." << endl;

  if (areIdentical(head1, head2)) {
    cout << "identical" << endl;
  } else {
    cout << "different" << endl;
  }

  return 0;
}
