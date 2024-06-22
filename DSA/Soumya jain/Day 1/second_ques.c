#include <stdio.h>
#include <stdlib.h>

int countPairs(int arr[], int n, int k){
    int count = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if((arr[i] + arr[j]) % k == 0){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int a, k;
    printf("Enter the size of array = ");
    scanf("%d", &a);
    
    int *arr = (int *)malloc(a * sizeof(int)); // Allocate memory for the array
    
    printf("Enter the integer k = ");
    scanf("%d", &k);

    printf("Enter the elements of array = \n");
    for(int i = 0; i < a; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    int result = countPairs(arr, a, k);
    printf("Number of valid pairs: %d\n", result);

    free(arr); // Free the allocated memory
    return 0;
}
