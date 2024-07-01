#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

typedef struct Queue 
{
    Node* front;
    Node* rear;
} Queue;

Node* Create_New_Node(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* Initialize_Queue() 
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data) 
{
    Node* newNode = Create_New_Node(data);
    if (q->rear == NULL) 
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) 
{
    if (q->front == NULL) 
    {
        return -1; // Queue is empty
    }

    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) 
    {
        q->rear = NULL;
    }

    free(temp);
    return data;
}

// Recursive function 
void Reverse_Queue(Queue* q) 
{
    if (q->front == NULL) 
    {
        return;
    }

    int data = dequeue(q);
    Reverse_Queue(q);
    enqueue(q, data);
}

void Display_Queue(Queue* q) 
{
    Node* temp = q->front;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() 
{
    Queue* q = Initialize_Queue();
    
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Original queue: ");
    Display_Queue(q);

    Reverse_Queue(q);
    printf("Reversed queue: ");
    Display_Queue(q);

    return 0;
}
