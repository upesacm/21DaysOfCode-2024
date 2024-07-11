#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

const char* hasCycle(struct ListNode *head) {
    struct ListNode *marker = (struct ListNode *)malloc(sizeof(struct ListNode)); 

    while (head != NULL) {
        if (head->next == marker) {
            free(marker); 
            return "cycle";
        }
        
        struct ListNode *temp = head->next;
        head->next = marker; 
        head = temp; 
    }

    free(marker); 
    return "no cycle";
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next; 

    printf("%s\n", hasCycle(head)); 

    return 0;
}
    printf("%s\n", hasCycle(head)); // Output: cycle

    return 0;
}
