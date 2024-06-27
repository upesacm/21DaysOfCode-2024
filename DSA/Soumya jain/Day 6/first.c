// write a function to checks if a singly linked list contains a cycle. 
//Return "cycle"if a loop exists, otherwise return "no cycle".

#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList* next;
};

char* hasCycle(struct LinkedList* head){
    if(head == NULL || head->next == NULL){
        return "no cycle";
    }
    struct LinkedList* slow = head;
    struct LinkedList* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        if(slow == fast){
            return "cycle";
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return "no cycle";
}

struct LinkedList* newNode(int value){
    struct LinkedList* node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    node -> data = value;
    node->next = NULL;
    return node;
}

int main(){
    struct LinkedList* node1 = newNode(1);
    struct LinkedList* node2 = newNode(2);
    struct LinkedList* node3 = newNode(3);
    struct LinkedList* node4 = newNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    printf("%s\n", hasCycle(node1));

    struct LinkedList* node5 = newNode(5);
    struct LinkedList* node6 = newNode(6);
    struct LinkedList* node7 = newNode(7);

    node5->next = node6;
    node6->next = node7;

    printf("%s\n", hasCycle(node5));

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);
    free(node7);
    return 0;
}
