#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to find the merge point in two linked lists
int findMergePoint(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1!= temp2) {
        if (temp1!= NULL) {
            temp1 = temp1->next;
        } else {
            temp1 = head2;
        }

        if (temp2!= NULL) {
            temp2 = temp2->next;
        } else {
            temp2 = head1;
        }
    }

    if (temp1!= NULL) {
        return temp1->data;
    } else {
        return -1; //Return -1 if no merge point is found
    }
}

int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    Node* head2 = createNode(4);
    head2->next = createNode(5);
    head2->next->next = head1->next->next; //Merge point

    int mergePoint = findMergePoint(head1, head2);
    printf("Merge point: %d\n", mergePoint);

    return 0;
}
