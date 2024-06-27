#include <iostream>
#include <cmath>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int findMergeNode(ListNode* head1, ListNode* head2) {
    // Get the lengths of both lists
    int len1 = 0, len2 = 0;
    ListNode* current1 = head1;
    ListNode* current2 = head2;
    
    while (current1) {
        len1++;
        current1 = current1->next;
    }
    while (current2) {
        len2++;
        current2 = current2->next;
    }
    
    // Reset pointers to the heads
    current1 = head1;
    current2 = head2;
    
    // Move the pointer of the longer list
    for (int i = 0; i < abs(len1 - len2); i++) {
        if (len1 > len2) {
            current1 = current1->next;
        } else {
            current2 = current2->next;
        }
    }
    
    // Move both pointers until they meet
    while (current1 != current2) {
        current1 = current1->next;
        current2 = current2->next;
    }
    return current1->val;
}

int main() {
    ListNode* common = new ListNode(3);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = common;
    ListNode* head2 = new ListNode(6);
    head2->next = new ListNode(7);
    head2->next->next = common;
    cout << "Merge point value: " << findMergeNode(head1, head2) << endl;
    
    return 0;
}
