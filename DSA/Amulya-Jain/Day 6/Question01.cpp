#include <iostream>
using namespace std;


struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

string isCyclic(Node *head) {
    if (!head) return "no cycle";
    
    Node *slow = head;
    Node *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return "cycle exists";
        }
    }
    
    return "no cycle exists";
}

void createCycle(Node *head, int pos) {
    if (pos == -1) return;
    
    Node *temp = head;
    Node *cycleNode = NULL;
    
    int index = 0;
    while (temp->next != NULL) {
        if (index == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        index++;
    }
    temp->next = cycleNode;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // we can use a random function to randomly create a cycle
    createCycle(head, 1); // Creating a cycle that points back to the node with value 2
    
    cout << isCyclic(head) << endl; 
    
    return 0;
}
