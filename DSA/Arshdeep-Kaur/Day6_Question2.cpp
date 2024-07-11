#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int length(ListNode *head) {
    int len = 0;
    ListNode *current = head;
    while (current != nullptr) {
        len++;
        current = current->next;
    }
    return len;
}

int findMergePoint(ListNode *headA, ListNode *headB) {
    int lenA = length(headA);
    int lenB = length(headB);

    ListNode *currentA = headA;
    ListNode *currentB = headB;

    // Adjust the starting points if lists have different lengths
    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff > 0) {
            currentA = currentA->next;
            diff--;
        }
    } else if (lenB > lenA) {
        int diff = lenB - lenA;
        while (diff > 0) {
            currentB = currentB->next;
            diff--;
        }
    }

    // Traverse both lists until a common node is found
    while (currentA != nullptr && currentB != nullptr) {
        if (currentA == currentB) {
            return currentA->val; // Found the merge point
        }
        currentA = currentA->next;
        currentB = currentB->next;
    }
}

int main() {
    // Creating linked list 1: 1 -> 2 -> 3
    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);

    // Creating linked list 2: 4 -> 5 -> 3
    ListNode *headB = new ListNode(4);
    headB->next = new ListNode(5);
    // Linking the lists at node with value 3
    headB->next->next = headA->next->next;

    int mergeValue = findMergePoint(headA, headB);
    if (mergeValue != -1) {
        cout << "Merge Point Value: " << mergeValue << endl;
    } else {
        cout << "No merge point found." << endl;
    }

    return 0;
}
