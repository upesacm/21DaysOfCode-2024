#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool areIdentical(ListNode* head1, ListNode* head2) {
    ListNode* current1 = head1;
    ListNode* current2 = head2;

    while (current1 != nullptr && current2 != nullptr) {
        if (current1->val != current2->val) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    return (current1 == nullptr && current2 == nullptr);
}

ListNode* createLinkedList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int n;

    std::cout << "Enter the number of elements in the linked list: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Enter value " << (i + 1) << ": ";
        std::cin >> value;

        ListNode* newNode = new ListNode(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    std::cout << "Create the first linked list:" << std::endl;
    ListNode* head1 = createLinkedList();

    std::cout << "Create the second linked list:" << std::endl;
    ListNode* head2 = createLinkedList();

    if (areIdentical(head1, head2)) {
        std::cout << "Identical" << std::endl;
    } else {
        std::cout << "Different" << std::endl;
    }

    return 0;
}
