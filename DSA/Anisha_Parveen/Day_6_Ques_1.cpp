#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Function to check if a singly linked list contains a cycle
string detectCycle(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return "cycle";
        }
    }
    return "no cycle";
}

// Function to print a linked list (for debugging purposes)
void printList(struct Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    struct Node *head = new Node();
    struct Node *second = new Node();
    struct Node *third = new Node();
    struct Node *fourth = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = second; 

    // Detect cycle in the list
    string result = detectCycle(head);
    cout << "Linked list has a " << result << endl;

    return 0;
}
