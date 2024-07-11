#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

char* compareLists(Node* list1, Node* list2) {
    while (list1!= NULL && list2!= NULL) {
        if (list1->data!= list2->data) {
            return "different";
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    if (list1!= NULL || list2!= NULL) {
        return "different";
    }

    return "identical";
}

int main() {
    Node* list1 = malloc(sizeof(Node));
    list1->data = 1;
    list1->next = malloc(sizeof(Node));
    list1->next->data = 2;
    list1->next->next = malloc(sizeof(Node));
    list1->next->next->data = 3;
    list1->next->next->next = NULL;

    Node* list2 = malloc(sizeof(Node));
    list2->data = 1;
    list2->next = malloc(sizeof(Node));
    list2->next->data = 2;
    list2->next->next = malloc(sizeof(Node));
    list2->next->next->data = 3;
    list2->next->next->next = NULL;
    printf("%s\n", compareLists(list1, list2));
    return 0;
}
