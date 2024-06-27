#include <stdio.h>
#include <stdlib.h>

struct Node
 {
    int data;
    struct Node* next;
};

void ins(struct Node** head, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head= newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) 
    {
        temp= temp->next;
    }
    temp->next = newNode ;
}
void printL(struct Node* head)
 {
    printf("The Linked List is:- ");
    while (head) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void rev(struct Node** head) 
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev ;
}

int main() 
{
    struct Node* head = NULL;
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the element:- ");
    for (int i = 0; i < n; i++) 
    {   int data;
        scanf("%d", &data);
        ins(&head, data);
    }
    printf("Original List: ") ;
    printL(head);

    rev(&head);
    printf("Reversed List: ");
    printL(head); 

    return 0;
}


