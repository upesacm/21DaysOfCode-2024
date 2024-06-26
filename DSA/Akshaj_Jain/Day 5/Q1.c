#include<stdio.h>
#include<stdlib.h>

  struct Node 
{
    int data;
    struct Node *next;
    struct Node *previous;
};

void main(){
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *p;

    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    first->data = 1;
    second->data = 2;
    third->data = 3;

    first->previous=NULL;
    second->previous=first;
    third->previous=second;

    p=third;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->previous;
    }
    
}

