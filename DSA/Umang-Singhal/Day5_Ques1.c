#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int main() {
    struct Node *head = NULL, *temp, *newNode;
    int n, value;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    int length = 0;
    temp = head;
    while(temp != NULL) {
        length++;
        temp = temp->next;
    }
    for(int i = length - 1; i >= 0; i--) {
        temp = head;
        for(int j = 0; j < i; j++) {
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    return 0;
}
