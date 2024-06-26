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

void printReverse(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
}

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
    Node *head = createLinkedList();
    cout << "The elements in reverse order are: ";
    printReverse(head);
    cout << endl;

    // Clean up memory
    deleteLinkedList(head);

    return 0;
}
