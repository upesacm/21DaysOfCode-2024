#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


const char* detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;


        if (slow == fast) {
            return "cycle";
        }
    }


    return "no cycle";
}


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    struct Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = head->next; 


    const char* result = detectCycle(head);
    printf("%s\n", result); 

    return 0;
}
