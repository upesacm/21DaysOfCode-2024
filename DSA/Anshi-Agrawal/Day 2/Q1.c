#include<stdio.h>
int main()
{
    int i,size,thres,count=0;
    //user to enter details
    printf("enter threshold number of students:");
    scanf("%d",&thres);
    printf("enter total number of arrival times:");
    scanf("%d",&size);
    int arr[size];
    for(i=0;i<size;i++)
    {
        printf("enter %d arrival time:",i+1);
        scanf("%d",&arr[i]);
        printf("\n");
    }
    for(i=0;i<size;i++) //checking
    {
        if(arr[i]<0)
        {
           count ++;
        }       
    }
    printf("all arival times:["); //displaying the arrival times
    for(i=0;i<size;i++)
    {
      printf("%d,",arr[i]);
    }
    printf("]\n");
    if(count<thres) //conclusion
    printf("YES class is cancelled");
    else
    printf("NO class is not canceleled");
    return 0;
}