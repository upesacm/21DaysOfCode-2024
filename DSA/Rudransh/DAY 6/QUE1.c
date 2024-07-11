#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *insterend(node *head, int value) {
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory allocation failed!!\n");
        return NULL;
    }
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode;
    }

    node *temp = head;
    node *temp2 = NULL;

    while (temp->next != NULL) {
        if (temp->data == value) {
            temp2 = temp->next;
        }
        temp = temp->next;
    }

    temp->next = newnode;
    if (temp2 != NULL) {
        newnode->next = temp2;
    }

    return head;
}

void print(node*head){
	if(head==NULL){
		return;
	}
	printf("%d",head->data);
	print(head->next);
}
const char*cycle_checker(node * head){
	node *temp=head,*temp2=head;
	while (temp2 != NULL && temp2->next != NULL) {
        temp = temp->next;
        temp2 = temp2->next->next;
        if (temp == temp2) {
            return "cycle";
        }
    }
    return "no cycle";
}
void main(){
char ch;
	printf("Do you want to enter elements(Y/N) : ");
	scanf(" %c",&ch);
	node *head=NULL;
	int loc;
	while(ch=='y'||ch=='Y'){
		int value;
		printf("Enter the value : ");
		scanf("%d",&value);
		head = insterend(head,value);
		printf("do you want to add another element(Y/N) : ");
		scanf(" %c",&ch);
	}
	const char*ans=cycle_checker(head);
	printf("%s",ans);   
}
