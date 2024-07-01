#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

string hasCycle(ListNode *head) {
    if (!head || !head->next) {
        return "No cycle";
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return "Cycle";
        }
    }

    return "No cycle";
}

int main() {
    // Creating a list with a cycle: 1 -> 2 -> 3 -> 4 -> 2 (cycle)
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;  // Creates a cycle

    cout << hasCycle(node1) << endl;

    return 0;
}
