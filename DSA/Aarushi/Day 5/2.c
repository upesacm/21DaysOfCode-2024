#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* createList() {
    int n, data;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        return head;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

const char* compareLists(struct Node* head1, struct Node* head2) {
    struct Node *temp1 = head1, *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data) {
            return "different";
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 == NULL && temp2 == NULL) {
        return "identical";
    } else {
        return "different";
    }
}

int main() {
    printf("Creating list 1:\n");
    struct Node* head1 = createList();

    printf("Creating list 2:\n");
    struct Node* head2 = createList();

    printf("Linked list 1:\n");
    printList(head1);

    printf("Linked list 2:\n");
    printList(head2);

    const char* result = compareLists(head1, head2);
    printf("Output: %s\n", result);

    return 0;
}
