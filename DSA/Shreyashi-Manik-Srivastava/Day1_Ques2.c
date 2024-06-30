#include<stdio.h>

int count_pairs(int arr[], int n, int k){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i]<arr[j] && (arr[i]+arr[j])%k==0){
                count++;
                printf("Valid pair: (%d, %d)\n", i, j);
            }
        }
    }
    printf("No. of valid pairs: %d\n", count);
}

int main(){
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    count_pairs(arr, n, 3);

    return 0;
}