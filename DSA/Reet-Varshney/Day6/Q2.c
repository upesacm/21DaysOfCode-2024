#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->next = NULL;
    return node;
}
int getListLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
int getMergePoint(struct Node* head1, struct Node* head2) {
    int len1 = getListLength(head1);
    int len2 = getListLength(head2);

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
            return head1->value;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}
int main() {
    struct Node* commonNode = newNode(3);

    struct Node* listA = newNode(1);
    listA->next = newNode(2);
    listA->next->next = commonNode;

    struct Node* listB = newNode(4);
    listB->next = newNode(5);
    listB->next->next = commonNode;
    int mergePoint = getMergePoint(listA, listB);
    if (mergePoint != -1) {
        printf("Merge point value: %d\n", mergePoint);
    } else {
        printf("No merge point found.\n");
    }
    free(listA->next->next);
    free(listA->next);
    free(listA);
    free(listB->next);
    free(listB);
    return 0;
}
