#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter n ");
    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i++){
        printf("Enter number ");
        scanf("%d",&arr[i]);
    }

    int day,month;
    printf("Enter month and day ");
    scanf("%d%d",&day,&month);
    int length=0,sum=0;

    // count with month 
    for(int i=0;i<n;i++){
        if(arr[i]==month){
            length++;
        }
    }

    int num=0;
    // count with sum
    for(i=0;i<n;i++){
        if(arr[i]<day){
            num=num+arr[i];
            for(j=i+1;j<n;j++){
                num=num+arr[j];
                if(num<day){
                }else if(num==day){
                        sum++;
                        num=0;
                        break;
                }else{
                    break;
                }
            }
        }
    }

    printf("Total to divide the bar is %d",length+sum);
    printf("\n%d",length);
    printf("\n%d",sum);
    return 0;
}
