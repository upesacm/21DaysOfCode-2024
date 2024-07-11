#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void addToQueue(Node** head, Node** tail, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void reverseQueue(Node** head, Node** tail) {
    if (*head == NULL) return;
    Node* temp = *head;
    *head = (*head)->next;
    if (*head == NULL) {
        *tail = NULL;
    }
    reverseQueue(head, tail);
    addToQueue(head, tail, temp->value);
    free(temp);
}

void displayQueue(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    addToQueue(&head, &tail, 1);
    addToQueue(&head, &tail, 2);
    addToQueue(&head, &tail, 3);

    printf("Queue before reversal: ");
    displayQueue(head);
    reverseQueue(&head, &tail);
    printf("Queue after reversal: ");
    displayQueue(head);

    return 0;
}
