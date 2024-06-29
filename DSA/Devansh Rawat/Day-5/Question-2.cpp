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