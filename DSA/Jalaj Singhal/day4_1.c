#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print(struct Node* head) {
    struct Node* stack[1000];
    int top = -1;
    struct Node* current = head;
    while (current != NULL) {
        stack[++top] = current;
        current = current->next;
    }
    while (top >= 0) {
        printf("%d ", stack[top--]->data);
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }
    printf("Linked list in reverse order: ");
    print(head);
    return 0;
}
