#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void reverse(struct node *head) {
    if (head == NULL) {
        return;
    }
    reverse(head->next);
    printf("%d ", head->val);
}

struct node* createNode(int val) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct node** head, int val) {
    struct node *newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    struct node *head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);

    printf("The reversed linked list is: ");
    reverse(head);
    printf("\n");

    return 0;
}
