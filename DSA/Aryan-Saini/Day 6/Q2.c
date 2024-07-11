#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

int findMergePoint(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }
    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node* head1 = newNode(1);
    head1->next = newNode(2);
    struct Node* mergeNode = newNode(3);
    head1->next->next = mergeNode;
    
    struct Node* head2 = newNode(4);
    head2->next = newNode(5);
    head2->next->next = mergeNode;

    int mergePoint = findMergePoint(head1, head2);
    if (mergePoint != -1) {
        printf("Merge point data: %d\n", mergePoint);
    } else {
        printf("No merge point found.\n");
    }

    return 0;
}
