 #include <bits/stdc++.h>
using namespace std;

 
class Node {
public:
    int data;
    Node* next;
      Node(int x) {
        data = x;
          next = NULL;
    }
};

 
Node* getIntesectionNode(Node* head1, Node* head2)
{
    while (head2) {
        Node* temp = head1;
        while (temp) {
          
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
   
    return NULL;
}

 
int main()
{ 

    Node* newNode;

   
    Node* head1 = new Node(1);
    Node* head2 = new Node(4);
  
    head1->next=new Node(2);
    head2->next = new Node(5);

    newNode = new Node(3);
    head1->next->next = newNode;
    head2->next->next = newNode;


    head1->next->next->next = NULL;

    Node* intersectionPoint
        = getIntesectionNode(head1, head2);

    if (!intersectionPoint)
        cout << " No Intersection Point \n";
    else
        cout << "Intersection Point: "
             << intersectionPoint->data << endl;
}
