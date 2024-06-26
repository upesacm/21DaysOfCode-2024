#include<stdio.h>
#include<stdlib.h>

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
const char* comp(node* head,node*head2){
	node* temp=head,*temp2=head2;
	while(temp->next!=NULL&&temp2->next!=NULL){
		if(temp->data!=temp2->data){
			return "different";
		}
		temp=temp->next;
		temp2=temp2->next;
	}
	if(temp->next!=NULL||temp2->next!=NULL){
		return "different";
	}
	return "identical";
}
void print(node*head){
	if(head==NULL){
		return;
	}
	printf("%d",head->data);
	print(head->next);
}
void main(){
	node *head=NULL;
	node*head2=NULL;
	for(int i =0;i<2;i++){
		char ch;
		int value;
		printf("Do you want to enter elements in linklist %d (Y/N) : ",i+1);
		scanf(" %c",&ch);
		if(i==0){
			while(ch=='y'||ch=='Y'){
				printf("Enter the value : ");
				scanf("%d",&value);
				head = insterend(head,value);
				printf("do you want to add another element(Y/N) : ");
				scanf(" %c",&ch);
			}
		}
		else{
			while(ch=='y'||ch=='Y'){
				printf("Enter the value : ");
				scanf("%d",&value);
				head2 = insterend(head2,value);
				printf("do you want to add another element(Y/N) : ");
				scanf(" %c",&ch);
			}
		}
	}
	const char *ans=comp(head,head2);
	printf("%s",ans);
}
