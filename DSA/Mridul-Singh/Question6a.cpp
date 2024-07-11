#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtBegin(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void insertAtEnd(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    if (head == nullptr) {
        head = temp;
    } else {
        Node* ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void display() {
    if (head == nullptr) {
        cout << "Empty" << endl;
    } else {
        Node* ptr = head;
        while (ptr != nullptr) {
            cout << ptr->data << "  ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

// Function to manually create a loop for testing
void createLoop(int position) {
    if (head == nullptr) return;

    Node* loopNode = nullptr;
    Node* temp = head;
    int count = 1;
    while (temp->next != nullptr) {
        if (count == position) {
            loopNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = loopNode;
}

//This function is using hashmap is check loop which takes time complexity O(n) and sapce O(n)
bool checkCycle(){
    unordered_set <Node*> s;
    Node* ptr=head;
    while(ptr!=NULL){
        if(s.find(ptr)!=s.end()){
            return true;
        }
        s.insert(ptr);
        ptr=ptr->next;
    }
    return false;
}

//This function is using slow and fast pointer is check loop which takes time complexity O(n) and sapce O(1)
bool CheckLoop()
{
    Node *slow = head, *fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main(){
    insertAtBegin(2);
    insertAtBegin(1);
    insertAtEnd(3);
    insertAtEnd(4);
    display();
    createLoop(2);
    if (CheckLoop())
        cout << "\nLoop Found";
    else
        cout << "\nNo Loop";
    return 0;
}