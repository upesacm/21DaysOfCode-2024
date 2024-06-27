//Find Merge Point in Linked Lists Determine the 
//node where two singly linked lists merge. Return the value of this node.

#include<stdio.h>
#include<stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList* next;
};

struct LinkedList* newNode(int value){
    struct LinkedList* node = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    node->data= value;
    node->next = NULL;
    return node;
}

int getLength(struct LinkedList* head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head -> next;
    }
    return length;
}

struct LinkedList* advanceListByN(struct LinkedList* head, int n){
    while(n>0 && head != NULL){
        head = head->next;
        n--;
    }
    return head;
}

int findMergeNode(struct LinkedList* list1, struct LinkedList* list2){
    int len1 = getLength(list1);
    int len2 = getLength(list2);

    if(len1 > len2){
        list1 = advanceListByN(list1, len1 - len2);
    }else{
        list2 = advanceListByN(list2, len2 - len1);
    }

    while(list1 != NULL && list2 != NULL){
        if(list1 == list2)
            return list1->data;
        list1 = list1->next;
        list2 = list2 -> next;
    }
    return -1;
}

int main(){
    struct LinkedList* node1 = newNode(1);
    struct LinkedList* node2 = newNode(2);
    struct LinkedList* node3 = newNode(3);
    struct LinkedList* node4 = newNode(4);
    struct LinkedList* node5 = newNode(5);

    node1->next = node2;
    node2->next = node3;
    node4->next = node3;
    node3->next = node5;

    int mergeValue = findMergeNode(node1, node4);
    if(mergeValue != -1)
        printf("Merge point value: %d\n", mergeValue);
    else
        printf("No merge point found.\n");

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    return 0;
}
