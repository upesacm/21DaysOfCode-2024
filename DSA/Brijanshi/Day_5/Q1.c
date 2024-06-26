#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printReverse(Node* head) {
    if (head == NULL) return; 
    printReverse(head->next);
    printf("%d ", head->data);
}
int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;
    printReverse(head); 
    return 0;
}
