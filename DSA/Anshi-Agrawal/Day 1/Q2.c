#include<stdio.h>
int main()
{
    int arr[]={1,3,2,6,1,2};
    int i,j,k=3,count=0,len;
    len=sizeof(arr)/sizeof(arr[0]);
    for (i=0;i<=len;i++)
    {
      for(j=len;j>i;j--)
      {
        int sum= arr[i]+ arr[j];
        if(sum%k==0)
        {
            count++;
        }
      }
    }
    printf("Total number of pairs:%d",count);
    return 0;

}