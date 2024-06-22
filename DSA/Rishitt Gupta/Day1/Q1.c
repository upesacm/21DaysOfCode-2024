//Simple Approach to it :)
#include <stdio.h>
int main()
{
    int a,b,c;
    // Number of Bars
    scanf("%d",&a);
    // Number on chocobars
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }
    //Day
    scanf("%d",&b);
    //Month
    scanf("%d",&c);
    int count=0;
    int main=0;
    for(int i=0;i<a-c;i++)
    {
        count = 0;
        for(int j=i;j<i+c;j++)
        {
            count=count+arr[j];   
        }
        if(count==b){
            main++;
        }
    }
    printf("ANSWER: %d", main);
}
