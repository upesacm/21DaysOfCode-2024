#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int getLength(struct ListNode *head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

int findMergePoint(struct ListNode *headA, struct ListNode *headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA->val;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return -1; 
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    struct ListNode* headA = newNode(1);
    headA->next = newNode(2);
    headA->next->next = newNode(3);

    struct ListNode* headB = newNode(4);
    headB->next = newNode(5);
    headB->next->next = headA->next->next; 

    int mergePoint = findMergePoint(headA, headB);
    if (mergePoint != -1) {
        printf("Merge Point: %d\n", mergePoint); 
    } else {
        printf("No merge point found\n");
    }

    return 0;
}
