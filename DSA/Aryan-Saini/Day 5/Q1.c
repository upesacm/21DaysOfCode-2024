#include <stdio.h>
#include <stdlib.h>

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

void printReverse(struct Node* head) {
    if (head == NULL)
        return;
    

    printReverse(head->next);
    
    printf("%d ", head->data);
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Reversed linked list: ");
    printReverse(head);
    printf("\n");

    return 0;
}
