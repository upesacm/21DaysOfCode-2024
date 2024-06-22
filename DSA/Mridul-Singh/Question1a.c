#include<stdio.h>

//  This is brute force approach (this is not the best optimal solution)
// Time complexity-> O(n2)

// int candySegment(int* arr,int days,int months,int size){
//     int res=0;
//     if(months>size){
//         return res;
//     }
//     for(int i=0;i<=size-months;i++){
//         int sum=0;
//         for(int j=i;j<i+months;j++){
//             sum+=arr[j];
//         }
//         if(sum==days){
//             res++;
//         }
//     }
//     return res;
// }


//In the below solution we are using sliding window approach (this is the best optimal solution)
// Time complexity-> O(n)

int candySegment(int* arr, int days, int months, int size) {
    int res = 0;
    int sum = 0;
    // Calculate the sum of the first window
    for (int i = 0; i < months; i++) {
        sum += arr[i];
    }
    if (sum == days) {
        res++;
    }
    for (int i = months; i < size; i++) {
        sum += arr[i] - arr[i - months];
        if (sum == days) {
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