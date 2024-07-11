#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

const char* cycle(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return "no cycle";
    }

    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return "cycle";
        }
    }

    return "no cycle";
}

struct node* createNode(int value) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct node* node1 = createNode(1);
    struct node* node2 = createNode(2);
    struct node* node3 = createNode(3);
    struct node* node4 = createNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; 

    const char* result = cycle(node1);
    printf("%s\n", result); 

    return 0;
}
