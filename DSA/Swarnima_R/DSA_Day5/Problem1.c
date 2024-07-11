/*

Question 1: Given a singly linked list, write a function to print the elements in reverse order.

Inputs:
A singly linked list.
Output:
The elements of the list in reverse order.

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

void printListInReverse(struct ListNode* head) {
    if (head == NULL) {
        return;
    }
    printListInReverse(head->next);
    printf("%d ", head->data);
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
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);

    printf("Original List: ");
    printList(head);

    printf("Reversed List: ");
    printListInReverse(head);
    printf("\n");

    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
