#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

string hasCycle(ListNode *head) {
    // If the list is empty or has only one node, there can't be a cycle
    if (head == nullptr || head->next == nullptr) {
        return "no cycle";
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast) {
        // If fast has reached the end, there is no cycle
        if (fast == nullptr || fast->next == nullptr) {
            return "no cycle";
        }

        // Move slow pointer by one step
        slow = slow->next;

        // Move fast pointer by two steps
        fast = fast->next->next;
    }

    // If we exit the while loop, it means slow and fast met, indicating a cycle
    return "cycle";
}

int main() {
    // Create a linked list with a cycle: 1 -> 2 -> 3 -> 4 -> 2
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;  // Create cycle

    cout << hasCycle(head) << endl;  // Should print "cycle"

    return 0;
}
