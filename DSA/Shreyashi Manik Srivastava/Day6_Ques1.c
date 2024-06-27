#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int detectLoop(Node* h) {
    Node* slow = h;
    Node* fast = h;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    Node* head1;
    Node* one1 = (Node*)malloc(sizeof(Node));
    Node* two1 = (Node*)malloc(sizeof(Node));
    Node* three1 = (Node*)malloc(sizeof(Node));
    Node* four1 = (Node*)malloc(sizeof(Node));
    Node* five1 = (Node*)malloc(sizeof(Node));

    one1->value = 1;
    two1->value = 2;
    three1->value = 3;
    four1->value = 4;
    five1->value = 2;

    one1->next = two1;
    two1->next = three1;
    three1->next = four1;
    four1->next = five1;
    five1->next = two1; 

    head1 = one1;

    if (detectLoop(head1)) {
        printf("cycle\n");
    } else {
        printf("no cycle\n");
    }

    free(one1);
    free(two1);
    free(three1);
    free(four1);
    free(five1);

    return 0;
}