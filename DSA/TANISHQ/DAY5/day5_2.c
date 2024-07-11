#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to compare two linked lists
char* areListsIdentical(Node* list1, Node* list2) {
    // If either list is null, they cannot be identical
    if (!list1 ||!list2) {
        return "different";
    }

    // Compare the lengths of both lists
    Node* temp1 = list1;
    Node* temp2 = list2;
    int len1 = 0, len2 = 0;
    while (temp1!= NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2!= NULL) {
        len2++;
        temp2 = temp2->next;
    }

    // If the lengths are not equal, the lists are different
    if (len1!= len2) {
        return "different";
    }

    // If the lengths are equal, compare corresponding nodes
    temp1 = list1;
    temp2 = list2;
    while (temp1!= NULL && temp2!= NULL) {
        if (temp1->data!= temp2->data) {
            return "different";
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    // If we reach here, all corresponding nodes matched
    return "identical";
}

int main() {
    // Creating two identical linked lists: 1 -> 2 -> 3
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Allocate nodes in the heap
    head1 = (Node*)malloc(sizeof(Node));
    head2 = (Node*)malloc(sizeof(Node));

    head1->data = 1;
    head1->next = (Node*)malloc(sizeof(Node));
    head2->data = 1;
    head2->next = (Node*)malloc(sizeof(Node));

    head1->next->data = 2;
    head1->next->next = (Node*)malloc(sizeof(Node));
    head2->next->data = 2;
    head2->next->next = (Node*)malloc(sizeof(Node));

    head1->next->next->data = 3;
    head1->next->next->next = NULL;
    head2->next->next->data = 3;
    head2->next->next->next = NULL;

    // Compare the linked lists
    char* result = areListsIdentical(head1, head2);
    printf("Are the lists identical? %s\n", result);

    return 0;
}
