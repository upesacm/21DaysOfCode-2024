#include <iostream>
using namespace std;

#define MAX 100 // Size of Stack

typedef struct Stack 
{
    int arr[MAX];
    int top;
} Stack;

typedef struct Queue 
{
    Stack stack1;
    Stack stack2;
} Queue;

void Initialize_Stack(Stack* s) 
{
    s->top = -1;
}

int isEmpty(Stack* s) 
{
    return s->top == -1;
}

int isFull(Stack* s) 
{
    return s->top == MAX - 1;
}

void push(Stack* s, int data) 
{
    if (isFull(s)) 
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->top)] = data;
}

int pop(Stack* s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void Initialize_Queue(Queue* q) 
{
    Initialize_Stack(&q->stack1);
    Initialize_Stack(&q->stack2);
}

void enqueue(Queue* q, int data) 
{
    push(&q->stack1, data);
}

int dequeue(Queue* q) 
{
    if (isEmpty(&q->stack2)) 
    {
        while (!isEmpty(&q->stack1)) 
        {
            push(&q->stack2, pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}

int main() 
{
    Queue q;
    Initialize_Queue(&q);
    cout << "Enqueuing: -" << endl;
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    cout << "Dequeuing: -" << endl;
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    cout << "Enqueuing: -" << endl;
    enqueue(&q, 4);

    cout << "Dequeuing: -" << endl;
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));
    return 0;
}
