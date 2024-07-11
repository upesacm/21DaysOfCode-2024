#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int length(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int findMergePoint(Node* head1, Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            head1 = head1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            head2 = head2->next;
        }
    }

    while (head1 != head2) {
        head1 = head1->next;
        head2 = head2->next;
    }

    return head1->data;
}

int main() {
    Node* head1 = malloc(sizeof(Node));
    head1->data = 1;
    head1->next = malloc(sizeof(Node));
    head1->next->data = 2;
    head1->next->next = malloc(sizeof(Node));
    head1->next->next->data = 3;

    Node* head2 = malloc(sizeof(Node));
    head2->data = 4;
    head2->next = malloc(sizeof(Node));
    head2->next->data = 5;
    head2->next->next = head1->next->next; 

    printf("%d\n", findMergePoint(head1, head2)); 

    return 0;
}
