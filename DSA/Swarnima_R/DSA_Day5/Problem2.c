/*
Question 2: Create a function to compare two singly linked lists and determine if they are identical.

Inputs:
Two singly linked lists.
Output:
"identical" if the lists are the same, otherwise "different".
*/

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode* next;
};

struct ListNode* createNode(int data) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

const char* compareLists(struct ListNode* head1, struct ListNode* head2) {
    struct ListNode* current1 = head1;
    struct ListNode* current2 = head2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            return "different";
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 == NULL && current2 == NULL) {
        return "identical";
    } else {
        return "different";
    }
}

void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    struct ListNode* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);

    printf("Linked list 1: ");
    printList(head1);

    printf("Linked list 2: ");
    printList(head2);

    printf("Comparison result: %s\n", compareLists(head1, head2));

    // Free allocated memory
    struct ListNode* temp;
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL) {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}
