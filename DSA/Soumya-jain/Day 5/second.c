// Create a function to compare two linked list and determine if they are identical
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert(struct node** q, int data){
    struct node* temp, *r;
    if(*q == NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = data;
        temp->next = NULL;
        *q = temp;
    }else{
        temp = *q;
        while(temp->next != NULL)
            temp = temp->next;
        r = (struct node*)malloc(sizeof(struct node));
        r->data = data;
        r->next = NULL;
        temp->next = r;
    }
}

void display(struct node* q){
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

int compareLists(struct node* head1, struct node* head2){
    while(head1 != NULL && head2 != NULL){
        if(head1->data != head2->data){
            return 0;
        }
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    if(head1 == NULL && head2 == NULL){
        return 1;// lists are identical
    }
    return 0;// lists are not identical
}

int main(){
    struct node *p1, *p2;
    int n1, n2;
    p1 = NULL;
    p2 = NULL;

    printf("Enter the number of elements you want in the first linked list: ");
    scanf("%d", &n1);
    for(int i = 0; i < n1; i++){
        int element;
        printf("Enter the element: ");
        scanf("%d", &element);
        insert(&p1, element);
    }

    printf("Enter the number of elements you want in the second linked list: ");
    scanf("%d", &n2);
    for(int i = 0; i < n2; i++){
        int element;
        printf("Enter the element: ");
        scanf("%d", &element);
        insert(&p2, element);
    }

    printf("First List: ");
    display(p1);

    printf("Second List: ");
    display(p2);

    if(compareLists(p1, p2)){
        printf("The lists are identical.\n");
    }else{
        printf("The lists are not identical.\n");
    }

    return 0;
}
