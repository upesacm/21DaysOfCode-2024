#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to find the merge point of two singly linked lists
int findMergePoint(Node* head1, Node* head2) {
    int len1 = 0, len2 = 0;
    Node* temp1 = head1, *temp2 = head2;

    // Calculate the length of the first linked list
    while (temp1!= NULL) {
        len1++;
        temp1 = temp1->next;
    }

    // Calculate the length of the second linked list
    while (temp2!= NULL) {
        len2++;
        temp2 = temp2->next;
    }

    // Move the longer list to the same length as the shorter list
    temp1 = head1;
    temp2 = head2;
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            temp1 = temp1->next;
        }
    } else {
        for (int i = 0; i < len2 - len1; i++) {
            temp2 = temp2->next;
        }
    }

    // Move both lists together and find the merge point
    while (temp1!= temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // Return the value of the merge point
    return temp1->data;
}

// Example usage
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
    head2->next->next = head1->next->next; // merge point

    printf("%d\n", findMergePoint(head1, head2)); // Output: 3

    return 0;
}