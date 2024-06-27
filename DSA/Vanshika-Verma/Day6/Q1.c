#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

char* check(Node* head)
 {
    if (head == NULL) return "No cycle";
    Node* s = head ;
    Node* f = head;
     while (f!= NULL && f->next!= NULL)
      {
        s = s->next;
        f = f->next->next ;
        if (s == f)
         {
            return "cycle";
        }
    }

    return "no cycle";
}
int main() {
    Node* node1 = (Node*)malloc(sizeof(Node));
     node1->val = 1;
    Node* node2 = (Node*)malloc(sizeof(Node) );
     node2->val = 2;
    Node* node3 = (Node*)malloc(sizeof(Node));
     node3->val = 3;
    Node* node4 = (Node*)malloc(sizeof(Node)) ;
    node4->val = 4; 
 
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; 
printf("%s\n", check(node1)); 

return 0;
}
