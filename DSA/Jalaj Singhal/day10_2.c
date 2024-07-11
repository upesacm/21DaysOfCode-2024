#include<stdio.h>
#include <stdlib.h>
struct QueueNode{
    int data;
    struct QueueNode* next;
};
struct Queue {
    struct QueueNode *front, *rear;
};
struct QueueNode* newNode(int data) {
    struct QueueNode *temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Queue* createQueue(){
    struct Queue*queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}
int isEmpty(struct Queue *queue) {
    return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int data){
    struct QueueNode *temp = newNode(data);
    if(isEmpty(queue)) {
        queue->front = queue->rear = temp;
        return;
    }
    queue->rear->next = temp;
    queue->rear = temp;
}
int dequeue(struct Queue* queue) {
    if(isEmpty(queue))
        return -1;
    struct QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if(queue->front == NULL);
        queue->rear = NULL;
    free(temp);
    return data;
}
void reverse(struct Queue* queue) {
    struct Stack {
        struct QueueNode* data;
        struct Stack* next;
    };
    struct Stack* top = NULL;
    while (!isEmpty(queue)) {
        struct QueueNode* temp = newNode(dequeue(queue));
        struct Stack* newStackNode = (struct Stack*)malloc(sizeof(struct Stack)); 
        newStackNode->data = temp;
        newStackNode->next = top;
        top = newStackNode;
    }
    while (top != NULL) {
        enqueue(queue, top->data->data);
        struct Stack* temp = top;
        top = top->next;
        free(temp->data);  
        free(temp);       
    }
}
void print(struct Queue *queue) {
    struct QueueNode *temp = queue->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;  
    }
    printf("\n");
}
int main() {
    struct Queue * queue = createQueue();
    int n, element;
    printf("Entre number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &element);
        enqueue(queue, element);
    }
    reverse(queue);
    printf("reversed queue: ");
    print(queue);
    return 0;
}
