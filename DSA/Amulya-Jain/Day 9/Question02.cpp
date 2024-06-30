#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For boolean type

typedef struct Stack 
{
    int size;
    char *pta; 
    int top;
} Stack;

void push(Stack *st, char element)
{
    if (!(st->top == st->size - 1)) st->pta[++st->top] = element;
}

char pop(Stack *st)
{
    if (!(st->top == -1)) return st->pta[st->top--];
    return -1; // Indicating stack is empty
}

char tos(Stack st) {
    if (!(st.top == -1)) return st.pta[st.top];
    return -1; // Indicating stack is empty
}

bool isValid(char* s) {
    Stack st;
    st.top = -1;
    st.size = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        st.size++;
        i++;
    }
    st.pta = (char *)malloc(st.size * sizeof(char));
    if (st.pta == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }
    
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
        {
            push(&st, s[i]);
        }
        if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
        {
            if (st.top == -1) {
                free(st.pta);
                return false;
            }
            if ((tos(st) == '(') && (s[i] == ')')) pop(&st);          
            else if ((tos(st) == '{') && (s[i] == '}')) pop(&st);         
            else if ((tos(st) == '[') && (s[i] == ']')) pop(&st); 
            else {
                free(st.pta);
                return false;
            }        
        } 
    }
    free(st.pta);
    if (st.top == -1) return true;
    return false;
}

int main() {
    char string1[] = "{[()]}";
    char string2[] = "{[(])}";

    printf("String: %s - %s\n", string1, isValid(string1) ? "YES" : "NO"); // Output: YES
    printf("String: %s - %s\n", string2, isValid(string2) ? "YES" : "NO"); // Output: NO

    return 0;
}
