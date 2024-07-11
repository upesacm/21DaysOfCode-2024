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

int length(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int length1 = length(head1);
    int length2 = length(head2);

    while (length1 > length2) {
        head1 = head1->next;
        length1--;
    }

    while (length2 > length1) {
        head2 = head2->next;
        length2--;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1 == head2) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return -1;
}

int main() {
    struct Node* commonNode = createNode(3);

    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = commonNode;

    struct Node* list2 = createNode(4);
    list2->next = createNode(5);
    list2->next->next = commonNode;

    int intersection = findIntersection(list1, list2);

    if (intersection != -1) {
        printf("The intersection value is: %d\n", intersection);
    } else {
        printf("No intersection found.\n");
    }

    free(list1->next->next);
    free(list1->next);
    free(list1);
    free(list2->next);
    free(list2);

    return 0;
}
