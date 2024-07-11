#include<stdio.h>

void cancel(int arr[], int n, int k){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            count++;
        }
    }
    if(count>=k){
        printf("No");
    }
    else{
        printf("Yes");
    }
}
int main(){
    int n, k;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the threshold number:");
    scanf("%d",&k);

    cancel(arr,n,k);
}