#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to detect a cycle in a linked list
const char* detectCycle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return "No cycle"; // No cycle
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps

        if (slow == fast) {
            return "Cycle"; // Cycle detected
        }
    }

    return "No cycle"; // No cycle
}

// Function to create a linked list based on user input
struct Node* createLinkedList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

// Optional function to create a cycle for testing
void createCycle(struct Node* head, int pos) {
    if (pos == -1) {
        return;
    }
    struct Node* temp = head;
    struct Node* cycleNode = NULL;
    int count = 0;

    while (temp->next != NULL) {
        if (count == pos) {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }

    temp->next = cycleNode;
}

int main() {
    struct Node* head = createLinkedList();

    // Optional: create a cycle for testing
    int cyclePos;
    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &cyclePos);
    createCycle(head, cyclePos);

    printf("%s\n", detectCycle(head));

    return 0;
}
