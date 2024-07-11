#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int check(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->value == head2->value) {
            return head1->value;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

int main() {
    Node* head1;
    Node* one1 = (Node*)malloc(sizeof(Node));
    Node* two1 = (Node*)malloc(sizeof(Node));
    Node* three1 = (Node*)malloc(sizeof(Node));

    one1->value = 1;
    two1->value = 2;
    three1->value = 3;

    one1->next = two1;
    two1->next = three1;
    three1->next = NULL;

    head1 = one1;

    Node* head2;
    Node* one2 = (Node*)malloc(sizeof(Node));
    Node* two2 = (Node*)malloc(sizeof(Node));
    Node* three2 = (Node*)malloc(sizeof(Node));

    one2->value = 4;
    two2->value = 5;
    three2->value = 3;

    one2->next = two2;
    two2->next = three2;
    three2->next = NULL;

    head2 = one2;

    printf("%d\n", check(head1, head2));

    free(one1);
    free(two1);
    free(three1);
    free(one2);
    free(two2);
    free(three2);

    return 0;
}