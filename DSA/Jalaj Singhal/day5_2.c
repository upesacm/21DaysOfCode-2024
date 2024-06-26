#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head;
    new_node->data = data;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}
int compareLists(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data)
            return 0; 
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == NULL && temp2 == NULL)
        return 1;
    return 0;
}
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n, data;
    printf("Enter number of elements for the first linked list: ");
    scanf("%d", &n);
    printf("Enter first linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head1, data);
    }
    printf("\nEnter number of elements for the second linked list: ");
    scanf("%d", &n);
    printf("Enter second linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&head2, data);
    }
    if (compareLists(head1, head2))
        printf("\nThe linked lists are identical.\n");
    else
        printf("\nThe linked lists are different.\n");

    return 0;
}
