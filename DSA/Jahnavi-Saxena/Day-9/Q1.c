#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int x)
{
    if(top == MAX - 1){
        printf("Overflow");
        return;
    }
    stack[++top]=x;
}
void pop()
{
    if(top == -1){
        printf("Underflow");
        return;
    }
    top--;
}
int max()
{
    int max = top;
    if(top == -1){
        printf("empty");
        return;
    }
    for(int i=0;i<=top;i++)
    {
        if(stack[i]>=max)
        {
            max = stack[i];
        }
    }
    printf("Max element is: %d",max);
    return max;
}
void print()
{
    printf("stack is:" );
    for(int i=0;i<=top;i++)
    {
        printf("%d\t",stack[i]);
    }
    printf("\n");
}
void main()
{
    push(3);
    print();
    push(4);
    print();
    push(5);
    print();
    pop();
    print();
    push(7);
    print();
    push(1);
    pop();
    print();
    print();
    push(9);
    print();
    max();

}
