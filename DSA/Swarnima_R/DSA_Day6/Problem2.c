/*
Question 2: Find Merge Point in Linked Lists Determine the node where two singly linked lists merge. Return the value of this node.

Inputs:
Two singly linked lists.
Output:
The value of the merging node.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* getIntersectionNode(int d, struct Node* head1, struct Node* head2) {
    struct Node* current1 = head1;
    struct Node* current2 = head2;
    
    for (int i = 0; i < d; i++) {
        if (current1 == NULL) {
            return NULL;
        }
        current1 = current1->next;
    }
    
    while (current1 != NULL && current2 != NULL) {
        if (current1 == current2) {
            return current1;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    
    return NULL;
}

int findMergePoint(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    if (c1 > c2) {
        d = c1 - c2;
        struct Node* intersectionNode = getIntersectionNode(d, head1, head2);
        if (intersectionNode != NULL) {
            return intersectionNode->data;
        }
    } else {
        d = c2 - c1;
        struct Node* intersectionNode = getIntersectionNode(d, head2, head1);
        if (intersectionNode != NULL) {
            return intersectionNode->data;
        }
    }
    
    return -1;
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    head1->next->next->next = createNode(6);
    head1->next->next->next->next = createNode(7);

    struct Node* head2 = createNode(4);
    head2->next = createNode(5);
    head2->next->next = head1->next->next; // Merge point at node with value 3

    int mergePoint = findMergePoint(head1, head2);
    if (mergePoint != -1) {
        printf("The merge point is %d\n", mergePoint);
    } else {
        printf("No merge point found\n");
    }

    // Free allocated memory (to avoid memory leaks)
    free(head1->next->next->next->next); // Free node with value 7
    free(head1->next->next->next);       // Free node with value 6
    free(head1->next->next);             // Free node with value 3
    free(head1->next);                   // Free node with value 2
    free(head1);                         // Free node with value 1
    free(head2->next);                   // Free node with value 5
    free(head2);                         // Free node with value 4

    return 0;
}
