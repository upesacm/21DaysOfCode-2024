#include<stdio.h>

int sum_digit(int n )
{
    if(n>10)
    {
        return n;
    }
    else{
        int sum=0;
        while(n>0)
        {
            sum+= n % 10;
            n/=10;
        }
        return sum_digit(n);
    }
}

int main()
{
    int num;
    printf("Enter the interger:")
    scanf("%d", &num);

    int result = sum_digit(n);
    printf("    The result is :", result);
    return 0;


}