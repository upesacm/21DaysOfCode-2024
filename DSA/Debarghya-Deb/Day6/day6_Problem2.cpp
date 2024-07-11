#include <iostream>
#include <bits/stdc++.h>
using namespace std;



class Node
{
public:
    int data;
    Node* next;
     Node(int d)
    {
      data = d;
      next = NULL;
    }
};

// function to find the intersection point of two lists
void MergeNode(Node* headA, Node* headB)
{
    unordered_set<Node*> hs;
    while (headA != NULL) {
        hs.insert(headA);
        headA = headA->next;
    }
    while (headB) {
        if (hs.find(headB) != hs.end()) {
            cout << headB->data << endl;
            break;
        }
        headB = headB->next;
    }
}



int main() 
{
     // list 1
     Node* headA = new Node(1);
     headA->next = new Node(2);
     headA->next->next = new Node(3);
    
     // list 2
     Node* headB = new Node(4);
     headB->next = new Node(5);
     headB->next->next = headA -> next -> next; //So the node is merging at 3.
     
     
          
    MergeNode(headA,headB);
      
       return 0;
}
