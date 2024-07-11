#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *insertend(node *head, int value) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed!!\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    return head;
}

void print(node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node* merge_point(node *head1, node *head2) {
    if (head1 == NULL || head2 == NULL) {
        return NULL;
    }

    node *a = head1;
    node *b = head2;

    while (a != b) {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }

    return a;
}
node* merger(node *head1, node *head2) {
    node *temp1 = head1;
    node *temp2 = head2;
    
    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                node *common = temp1;
                while (temp1->next != NULL) {
                    temp1 = temp1->next;
                }
                temp1->next = common;
                return head1;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    
    return head1;
}

int main() {
	printf("I have manually created the link list because creating a link list with a common ")
    node *head1 = NULL;
    node *head2 = NULL;
    head1 = insertend(head1, 1);
    head1 = insertend(head1, 2);
    node *common = (node *)malloc(sizeof(node));
    if (common == NULL) {
        printf("Memory allocation failed!!\n");
        return 1;
    }

    common->data = 3;
    common->next = NULL;
    head1->next->next = common;
    head2 = insertend(head2, 4);
    head2 = insertend(head2, 5);
    head2->next->next = common;
    node *ans = merge_point(head1, head2);
    if (ans == NULL) {
        printf("No merge point\n");
    } else {
        printf("Merge point data: %d\n", ans->data);
    }

    return 0;
}
