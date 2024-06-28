#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void printReverse(struct Node *head) {
    if (head == NULL) {
        return;
    }
    printReverse(head->next);
    printf("%d ", head->value);
}

struct Node* createNode(int value) {
    struct Node newNode = (struct Node)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void appendNode(struct Node** head, int value) {
    struct Node *newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    struct Node *head = NULL;
    int n, value;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        appendNode(&head, value);
    }
    printf("The reversed linked list is: ");
    printReverse(head);
    printf("\n");
    return 0;
}
