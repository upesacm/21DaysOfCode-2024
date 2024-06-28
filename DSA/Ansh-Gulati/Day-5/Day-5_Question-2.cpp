#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

Node *createLinkedList()
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

bool compareLinkedLists(Node *head1, Node *head2)
{
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == nullptr && head2 == nullptr);
}

void deleteLinkedList(Node *head)
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    cout << "Create the first linked list:" << endl;
    Node *head1 = createLinkedList();

    cout << "Create the second linked list:" << endl;
    Node *head2 = createLinkedList();

    if (compareLinkedLists(head1, head2))
    {
        cout << "identical" << endl;
    }
    else
    {
        cout << "different" << endl;
    }

    // Clean up memory
    deleteLinkedList(head1);
    deleteLinkedList(head2);

    return 0;
}
