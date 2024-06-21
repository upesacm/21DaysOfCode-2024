# This is **Mridul Singh** .md file for DSA Questions
### Language Used C/C++
### Question 1 (a)

```c
#include<stdio.h>

int candySegment(int* arr,int days,int months,int size){
    int res=0;
    if(months>size){
        return res;
    }
    for(int i=0;i<=size-months;i++){
        int sum=0;
        for(int j=i;j<i+months;j++){
            sum+=arr[j];
        }
        if(sum==days){
            res++;
        }
    }
    return res;
}

int main(){
    int arr[5]={2,2,1,3,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int days=4;
    int months=2;
    printf("Number of possible ways he can break candy into segment is: %d",candySegment(arr,days,months,size));
    return 0;
}

