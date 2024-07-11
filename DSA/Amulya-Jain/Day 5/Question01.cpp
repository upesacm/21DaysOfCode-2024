#include <iostream>
using namespace std;

struct ListNode 
{
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

// used recursion
void printReverse(ListNode* head) 
{
    if (head == nullptr)
        return;
    
    printReverse(head->next);
    cout << head->val << " ";
}

int main() 
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    cout << "Linked list: ";
    ListNode* current = head;
    while (current != nullptr) 
    {
        cout << current->val;
        if (current->next != nullptr)
            cout << " -> ";
        current = current->next;
    }
    cout << endl;
    
    cout << "Output: ";
    printReverse(head);
    cout << endl;
    
    // Free allocated memory
    while (head != nullptr) 
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
