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

string hasCycle(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return "no cycle"; 
  }

  Node* slow = head;
  Node* fast = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      return "cycle";
    }
  }

  return "no cycle";
}

int main() {

  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = head->next;
  string result = hasCycle(head);
  cout << result << endl; 

  return 0;
}
