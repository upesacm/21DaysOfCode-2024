#include<stdio.h>

//In thsi solution we are using brute force approach 
// Time complexity-> O(n2)

int findNoPairs(int* arr,int size, int k){
    int res=0;
    for(int i=0;i<size-1;i++){
        int sum=0;
        for(int j=i+1;j<size;j++){
            sum=arr[i]+arr[j];
            if(sum%k==0){
                res++;
            }
        }
    }
    return res;
}

int main(){
    int arr[6]={1,3,2,6,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    printf("Number of pairs divisible by %d are : %d",k,findNoPairs(arr,size,k));
    return 0;
}