#include <stdio.h>

int main() {
    int n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n]; 
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the integer k: ");
    scanf("%d", &k);
    
    int count = 0;
        for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    
    printf("Number of valid (i, j) pairs: %d\n", count);
    
    return 0;
}

