#include<stdio.h>
#include<string.h>
#define SIZE 10
int top = -1;
char brackets[SIZE];

void push(char ch)
{
    if(top == SIZE-1)
    {
        printf("overflow");
        return;
    }
    brackets[++top]=ch;
}
void pop()
{
    if(top == -1){
        printf("undeflow");
        return ;
    }
    top--;
}

const char* is_balanced( const char* brackets[])
{
    for(int i=0;brackets[i]<'\0';i++)
    {
        char b = brackets[i];

        if(b == '(' || b == '{' || b == '[')
        {
            push(b);
        }
        else if(b == ')'|| b == '}' || b == ']')
        {
            if(top == -1){
                return "NO";
            }
            char pop_bracket=brackets[top--];
            if(b == '(' && pop_bracket != ')'||
            b == '{' && pop_bracket != '}' ||
            b == '[' && pop_bracket != ']'){
                return "NO";
            }
            
        }
    }
    return (top == -1) ? "YES" : "NO";
}
void main()
{
     const char* brackets = "{[()]}";
    printf("%s\n", is_balanced(brackets));
}
