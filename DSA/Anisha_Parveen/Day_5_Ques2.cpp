#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Function to compare if two linked lists are identical
bool areIdentical(struct Node *a, struct Node *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
            return false;

        a = a->next;
        b = b->next;
    }

    // If both lists are NULL at the same time, they are identical
    return (a == NULL && b == NULL);
}

void pushBack(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    struct Node *last = *head_ref;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Function to print a linked list
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
    struct Node *a = NULL;
    struct Node *b = NULL;

    pushBack(&a, 1);
    pushBack(&a, 2);
    pushBack(&a, 3);

    pushBack(&b, 1);
    pushBack(&b, 2);
    pushBack(&b, 3);

    cout << "List a: ";
    printList(a);
    cout << "List b: ";
    printList(b);

    if (areIdentical(a, b))
        cout << "Lists are identical\n";
    else
        cout << "Lists are not identical\n";

    return 0;
}
