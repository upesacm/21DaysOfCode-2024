#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    int n1, n2, data;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL, *last = NULL;
    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &data);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        if (head1 == NULL) {
            head1 = temp;
        } else {
            last->next = temp;
        }
        last = temp;
    }
    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second list:\n");
    last = NULL;
    for (int i = 0; i < n2; i++) {
        scanf("%d", &data);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->next = NULL;
        if (head2 == NULL) {
            head2 = temp;
        } else {
            last->next = temp;
        }
        last = temp;
    }
    struct Node* current1 = head1;
    struct Node* current2 = head2;
    int identical = 1;
    while (current1 != NULL && current2 != NULL) {
        if (current1->data != current2->data) {
            identical = 0;
            break;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
    if (current1 != NULL || current2 != NULL) {
        identical = 0;
    }
    if (identical) {
        printf("identical\n");
    } else {
        printf("different\n");
    }
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
    while (head2 != NULL) {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }
    return 0;
}
