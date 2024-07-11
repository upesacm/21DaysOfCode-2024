#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;
    
    ListNode(int val) : value(val), next(nullptr) {}
};

std::string hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return "no cycle";
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) {
            return "cycle";
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return "no cycle";
}

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3; 

    std::cout << hasCycle(node1) << std::endl;

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
  
    node1 = new ListNode(1);
    node2 = new ListNode(2);
    node3 = new ListNode(3);
    node4 = new ListNode(4);
    node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    std::cout << hasCycle(node1) << std::endl;  

    delete node1;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    return 0;
}
