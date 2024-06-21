#include <stdio.h>
#include <stdlib.h>

int CountPairs(int* arr, int n, int k) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
           
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n, k;
    
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
   
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
   
    int result = CountPairs(arr, n, k);
    printf("Number of valid (i, j) pairs: %d\n", result);
    
    
    return 0;
}
