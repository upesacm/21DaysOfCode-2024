#include <stdio.h>
#include <stdlib.h>
void enqueue(int *queue, int *rear, int value) {
    queue[*rear] = value;
    (*rear)++;
}
int dequeue(int *queue, int *front) {
    int value = queue[*front];
    (*front)++;
    return value;
}
void reverseQueue(int *queue, int *front, int *rear) {
    if (*front == *rear) {
        return;
    }
    int data = dequeue(queue, front);
    reverseQueue(queue, front, rear);
    queue[*rear] = data;
    (*rear)++;
}
void printQueue(int *queue, int front, int rear) {
    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int n, value;
    int front = 0, rear = 0;
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    int *queue = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(queue, &rear, value);
    }
    printf("Original Queue: ");
    printQueue(queue, front, rear);
    reverseQueue(queue, &front, &rear);
    printf("Reversed Queue: ");
    printQueue(queue, front, rear);
    free(queue);
    return 0;
}
