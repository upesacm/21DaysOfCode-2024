#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *insterend(node *head, int value){
	node *newnode= (node *)malloc(sizeof(node));
	if(newnode==NULL){
		printf("Memory allocation failed !!");
		return NULL;
	}
	newnode->data = value;
	newnode->next = NULL;
	if(head==NULL){
		return newnode;
	}
	node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
	return head;
}
void print(node*head){
	if(head==NULL){
		return;
	}
	printf("%d",head->data);
	print(head->next);
}
void reverse_print(node*head){
	if(head==NULL){
		return;
	}
	reverse_print(head->next);
	printf("%d",head->data);
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
	printf("Current elements of the Link List : \n");
	print(head);
	printf("\nThe elements in reverse order are : \n");
	reverse_print(head);
}
