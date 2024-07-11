#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void print()
{
    struct node *temp=head;
    printf("list is:\n");
    while(temp != NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct node *create(int x)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->data=x;
    new->next=NULL;
    return new;
}
void insert(int x)
{
    struct node *new=create(x);
    struct node *temp=head;
    if(head==NULL)
    {
        head=new;
        return;
    }
    new->next=head;
    head=new;
}
void reverse()
{
    struct node *current,*prev,*next;
    current=head;
    while(current != NULL)
    {
        next=current->next;
        current->next=prev;//link change hoga
        prev=current;
        current=next;
    }
    head=prev;
}
void main()
{
    head=NULL;
    insert(3);
    insert(4);
    insert(5);
    insert(5);
    insert(9);
    insert(8);
    print();
    printf("reversed link :\n");
    reverse();
    print();
}
