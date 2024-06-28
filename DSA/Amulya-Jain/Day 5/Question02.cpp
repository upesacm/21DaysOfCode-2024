#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};


bool CheckEqualLL(ListNode* head1, ListNode* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val != head2->val)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == nullptr && head2 == nullptr);
}

int main() 
{
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    
    cout << "Linked list 1: ";
    ListNode* current1 = head1;
    while (current1 != nullptr) 
    {
        cout << current1->val;
        if (current1->next != nullptr)
            cout << " -> ";
        current1 = current1->next;
    }
    cout << endl;
    
    cout << "Linked list 2: ";
    ListNode* current2 = head2;
    while (current2 != nullptr) 
    {
        cout << current2->val;
        if (current2->next != nullptr)
            cout << " -> ";
        current2 = current2->next;
    }
    cout << endl;
    
    bool result = CheckEqualLL(head1, head2);
    if (result)
        cout << "Output: identical" << endl;
    else
        cout << "Output: different" << endl;
    
    // Free allocated memory
    while (head1 != nullptr) 
    {
        ListNode* temp = head1;
        head1 = head1->next;
        delete temp;
    }
    
    while (head2 != nullptr) 
    {
        ListNode* temp = head2;
        head2 = head2->next;
        delete temp;
    }
    
    return 0;
}
