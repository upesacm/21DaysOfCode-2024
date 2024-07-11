#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int compareLists(Node* head1, Node* head2) {
    while (head1 && head2) {
        if (head1->data != head2->data) {
            return 0; 
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if (head1 || head2) {
        return 0;
    }
    return 1; 
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    int n;

    printf("Enter the number of elements for list 1: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element %d for list 1: ", i + 1);
        scanf("%d", &data);
        insert(&head1, data);
    }
    printf("List 1: ");
    printList(head1);

    printf("Enter the number of elements for list 2: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter element %d for list 2: ", i + 1);
        scanf("%d", &data);
        insert(&head2, data);
    }
    printf("List 2: ");
    printList(head2);

    int result = compareLists(head1, head2);
    if (result) {
        printf("The lists are identical.\n");
    } else {
        printf("The lists are not identical.\n");
    }

    return 0;
}