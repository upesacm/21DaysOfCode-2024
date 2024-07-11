#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int data;
    struct Stack* next;
    struct Stack* maxNext;
} Stack;

Stack* initStack() {
    return NULL;
}

void push(Stack** s, int x) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = x;
    newNode->next = *s;
    newNode->maxNext = NULL;
    if (*s == NULL || x >= (*s)->data) {
        newNode->maxNext = newNode;
    } else {
        newNode->maxNext = (*s)->maxNext;
    }
    *s = newNode;
}

int pop(Stack** s) {
    if (*s == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    int x = (*s)->data;
    Stack* temp = *s;
    *s = (*s)->next;
    free(temp);
    return x;
}

int get_max(Stack* s) {
    if (s == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->maxNext->data;
}

int main() {
    Stack* s = initStack();
    
    push(&s, 5);
    push(&s, 10);
    push(&s, 3);
    push(&s, 15);
    printf("%d\n", get_max(s));  
    pop(&s);
    printf("%d\n", get_max(s));  
    printf("%d\n", get_max(s)); 
    
    return 0;
}