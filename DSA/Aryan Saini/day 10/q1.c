#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


int isEmpty(struct Node* front) {
    return front == NULL;
}


void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* temp = newNode(data);
    if (*rear == NULL) {
        *front = *rear = temp;
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}


int dequeue(struct Node** front, struct Node** rear) {
    if (isEmpty(*front)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}


void reverseQueue(struct Node** front, struct Node** rear) {
    if (isEmpty(*front))
        return;
    int data = dequeue(front, rear);
    reverseQueue(front, rear);
    enqueue(front, rear, data);
}


void printQueue(struct Node* front) {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;

    int queue[] = {1, 2, 3};
    int n = sizeof(queue) / sizeof(queue[0]);
    
 
    for (int i = 0; i < n; ++i) {
        enqueue(&front, &rear, queue[i]);
    }

    printf("Original Queue: ");
    printQueue(front);

    reverseQueue(&front, &rear);

    printf("Reversed Queue: ");
    printQueue(front);

    return 0;
}
