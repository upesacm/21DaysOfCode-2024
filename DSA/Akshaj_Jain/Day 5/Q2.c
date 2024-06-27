#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode* next;
};

const char* compare_linked_lists(struct ListNode* head1, struct ListNode* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->value != head2->value) {
            return "different";
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == NULL && head2 == NULL) {
        return "identical";
    }
    return "different";
}
struct ListNode* create_node(int value) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int main() {
    struct ListNode* head1 = create_node(1);
    head1->next = create_node(2);
    head1->next->next = create_node(3);

    struct ListNode* head2 = create_node(1);
    head2->next = create_node(2);
    head2->next->next = create_node(3);

    const char* result = compare_linked_lists(head1, head2);
    printf("The linked lists are %s.\n", result);

    free(head1->next->next);
    free(head1->next);
    free(head1);
    free(head2->next->next);
    free(head2->next);
    free(head2);

    return 0;
}
