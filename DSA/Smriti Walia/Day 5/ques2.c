#include <stdio.h>
#include <stdlib.h>

struct LL {
    int data;
    struct LL *next;
};

void insertAtBeginning(struct LL** head, int dataToBeInserted) {
    struct LL* curr = (struct LL*)malloc(sizeof(struct LL));
    curr->data = dataToBeInserted;
    curr->next = NULL;

    if (*head == NULL)
        *head = curr; 
    else {
        curr->next = *head; 
        *head = curr;
    }
}

int isIdentical(struct LL** head1, struct LL** head2) {
    struct LL *temp1 = *head1, *temp2 = *head2;

    while (temp1 != NULL && temp2 != NULL) { 
        if (temp1->data != temp2->data) //match each element's data
            return 0;
      
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    //if any list remains untraversed means the lists are not identical
    if (temp1 || temp2)
        return 0;
    return 1;
}

void display(struct LL** head) {
    struct LL* temp = *head;
    while (temp != NULL) {
        if (temp->next != NULL)
            printf("%d -> ", temp->data);
        else
            printf("%d", temp->data);

        temp = temp->next; // move to next node
    }
    
    printf("\n");
}

void createList(struct LL** head, int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insertAtBeginning(head, data);
    }
}

int main() {
    struct LL *head1 = NULL;
    struct LL *head2 = NULL;
    int n;

    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n);
    printf("Enter the elements of the first list:\n");
    createList(&head1, n);

    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n);
    printf("Enter the elements of the second list:\n");
    createList(&head2, n);

    printf("First list is :-\n");
    display(&head1);

    printf("\nSecond list is :-\n");
    display(&head2);

    if (isIdentical(&head1, &head2))
        printf("\nGiven lists are identical\n");
    else
        printf("\nGiven lists are unidentical\n");

    return 0;
}
