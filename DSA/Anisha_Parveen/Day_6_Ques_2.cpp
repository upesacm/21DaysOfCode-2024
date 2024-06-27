#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int getLength(struct Node *head)
{
    int length = 0;
    while (head != NULL)
    {
        length++;
        head = head->next;
    }
    return length;
}

int findMergePoint(struct Node *head1, struct Node *head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        int diff = len2 - len1;
        while (diff--)
        {
            head2 = head2->next;
        }
    }

    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
        {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}


int main()
{
    struct Node *newNode;

    struct Node *head1 = new Node();
    head1->data = 1;
    head1->next = new Node();
    head1->next->data = 2;
    head1->next->next = new Node();
    head1->next->next->data = 3;
    head1->next->next->next = NULL;

    struct Node *head2 = new Node();
    head2->data = 4;
    head2->next = new Node();
    head2->next->data = 5;
    head2->next->next = head1->next->next;

    int mergePoint = findMergePoint(head1, head2);
    if (mergePoint != -1)
    {
        cout << "The merge point is: " << mergePoint << endl;
    }
    else
    {
        cout << "There is no merge point." << endl;
    }

    return 0;
}
