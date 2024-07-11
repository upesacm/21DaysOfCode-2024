#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;
    
    ListNode(int val) : value(val), next(nullptr) {}
};

int findMergePoint(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return -1;

    ListNode* pointerA = headA;
    ListNode* pointerB = headB;

    // Traverse both lists, redirecting to the head of the other list upon reaching the end.
    while (pointerA != pointerB) {
        pointerA = (pointerA == nullptr) ? headB : pointerA->next;
        pointerB = (pointerB == nullptr) ? headA : pointerB->next;
    }

    // If they met at the merge point, return its value, otherwise return -1.
    return (pointerA != nullptr) ? pointerA->value : -1;
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);

    node1->next = node2;
    node2->next = node3;
    node3->next = node6;
    node6->next = node7;

    node4->next = node5;
    node5->next = node6; 

    std::cout << "Merge Point Value: " << findMergePoint(node1, node4) << std::endl;  

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;
    delete node7;

    return 0;
}
