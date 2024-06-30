#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};


void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

bool areIdentical(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }


    return (head1 == NULL && head2 == NULL);
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int n1, n2, data;

    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);

    printf("Enter the elements of the first linked list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        append(&head1, data);
    }

    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);

    printf("Enter the elements of the second linked list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        append(&head2, data);
    }

    if (areIdentical(head1, head2)) {
        printf("identical\n");
    } else {
        printf("different\n");
    }

    return 0;
}
