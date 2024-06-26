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
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
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

const char* cycle(struct node *head)
{
    if(!head)
    {
        return "no cycle";
    }
    struct node *slow=head;
    struct node *fast=head;
    while(fast != NULL && fast->next !=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow=fast)
        {
            return "cycle";
        }
    }
    return "no cylce";
}
void main()
{
    head=NULL;
    insert(3);
    insert(4);
    insert(3);
    insert(3);
    insert(4);
    insert(3);
    print();
    printf("%s\n",cycle(head));
}
