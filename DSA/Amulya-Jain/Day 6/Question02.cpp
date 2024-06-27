#include <iostream>
using namespace std;

struct Node 
{
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

int Size_LL(Node *head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

Node* advanceBy(Node *head, int steps) {
    while (steps > 0 && head != NULL) {
        head = head->next;
        steps--;
    }
    return head;
}

int IntersectionPoint(Node *headA, Node *headB) {
    int lengthA = Size_LL(headA);
    int lengthB = Size_LL(headB);
    
    if (lengthA > lengthB) {
        headA = advanceBy(headA, lengthA - lengthB);
    } else {
        headB = advanceBy(headB, lengthB - lengthA);
    }
    
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA->val;
        }
        headA = headA->next;
        headB = headB->next;
    }
    
    return -1; // If no merge point is found
}

int main() 
{
    // Creating first linked list: 1 -> 2 -> 3
    Node *headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    
    // Creating second linked list: 4 -> 5 -> 3
    Node *headB = new Node(4);
    headB->next = new Node(5);
    headB->next->next = headA->next->next; // Merging point at node with value 3
    
    cout << IntersectionPoint(headA, headB) << endl; // Output: 3
    
    return 0;
}
