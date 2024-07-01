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

const char* compareLists(struct Node* head1, struct Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->data != head2->data) {
            return "different";
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 == NULL && head2 == NULL) {
        return "identical";
    } else {
        return "different";
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);
    struct Node* head2 = createNode(1);
    head2->next = createNode(2);
    head2->next->next = createNode(3);
    const char* result = compareLists(head1, head2);
    printf("The linked lists are %s\n", result);
    while (head1 != NULL) {
        struct Node* temp = head1;
        head1 = head1->next;
        free(temp);
    }

    while (head2 != NULL) {
        struct Node* temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}
