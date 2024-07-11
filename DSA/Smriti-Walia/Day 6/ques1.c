#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//Function to create a new Node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to insert a Node at the end of the linked list
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Function to detect a cycle in a linked list
char* hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return "cycle"; // Cycle detected
        }
    }

    return "no cycle"; // No cycle found
}

int main() {
    Node* head = NULL;

    int n;
    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNode(&head, data);
    }

    int cycleNode;
    printf("Enter the node to create a cycle: ");
    scanf("%d", &cycleNode);

    if (cycleNode != 0) {
        Node* temp = head;
        for (int i = 0; i < cycleNode - 1; i++) {
            temp = temp->next;
        }
        Node* cyclePtr = head;
        for (int i = 0; i < n; i++) {
            if (i == cycleNode - 1) {
                temp->next = cyclePtr;
                break;
            }
            cyclePtr = cyclePtr->next;
        }
    }

    printf("%s\n", hasCycle(head)); 

    return 0;
}
