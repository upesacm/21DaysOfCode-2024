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

void reverse(struct node** q){
    struct node* prev = NULL;
    struct node* current = *q;
    struct node* next = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *q = prev;
}

int main(){
    struct node* p;
    int n;
    p = NULL;

    printf("Enter the number of elements you want in the linked list: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int element;
        printf("Enter the element: ");
        scanf("%d", &element);
        insert(&p, element);
    }
    printf("Original List: ");
    display(p);

    reverse(&p);

    printf("Reversed List: ");
    display(p);

    return 0;
}
