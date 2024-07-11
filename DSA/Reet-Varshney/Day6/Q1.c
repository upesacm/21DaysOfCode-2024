#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};
const char* detectCycle(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return "No cycle detected";
    }
    struct Node *slowPtr = head;
    struct Node *fastPtr = head;
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr) {
            return "Cycle detected";
        }
    }

    return "No cycle detected";
}
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
    struct Node* nodeA = createNode(1);
    struct Node* nodeB = createNode(2);
    struct Node* nodeC = createNode(3);
    struct Node* nodeD = createNode(4);

    nodeA->next = nodeB;
    nodeB->next = nodeC;
    nodeC->next = nodeD;
    nodeD->next = nodeB; 

    const char* result = detectCycle(nodeA);
    printf("%s\n", result);

    return 0;
}
