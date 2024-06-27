#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list based on an array of data
struct node* createLinkedListFromArray(int data[], int n) {
    struct node* head = NULL;
    struct node* tail = NULL;

    for (int i = 0; i < n; i++) {
        struct node* newNode = createNode(data[i]);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Function to count nodes in a linked list
int getCount(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to get the intersection node
struct node* getIntersectionNode(int d, struct node* head1, struct node* head2) {
    struct node* current1 = head1;
    struct node* current2 = head2;
    
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

// Function to find the merge point
int findMergePoint(struct node* head1, struct node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    if (c1 > c2) {
        d = c1 - c2;
        struct node* intersectionNode = getIntersectionNode(d, head1, head2);
        if (intersectionNode != NULL) {
            return intersectionNode->data;
        }
    } else {
        d = c2 - c1;
        struct node* intersectionNode = getIntersectionNode(d, head2, head1);
        if (intersectionNode != NULL) {
            return intersectionNode->data;
        }
    }

    return -1;
}

int main() {
    // Creating first linked list: 1 -> 2 -> 3
    int data1[] = {1, 2, 3};
    struct node* head1 = createLinkedListFromArray(data1, 3);

    // Creating second linked list: 4 -> 5 -> 3 (sharing node '3')
    int data2[] = {4, 5};
    struct node* head2 = createLinkedListFromArray(data2, 2);
    head2->next->next = head1->next->next; // Manually creating merge point at node '3'

    int mergePoint = findMergePoint(head1, head2);
    if (mergePoint != -1) {
        printf("The merge point is %d\n", mergePoint);
    } else {
        printf("No merge point found\n");
    }

    return 0;
}
