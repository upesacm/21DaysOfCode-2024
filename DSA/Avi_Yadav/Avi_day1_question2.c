#include <stdio.h>

int count_divisible_pairs(int arr[], int n, int k) {
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

    // Taking input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declaring the array
    int arr[n];

    // Taking input for the elements of the array
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking input for the divisor k
    printf("Enter the integer k: ");
    scanf("%d", &k);

    // Calculating the number of valid pairs
    int result = count_divisible_pairs(arr, n, k);
    
    // Outputting the result
    printf("Number of valid (i, j) pairs: %d\n", result);

    return 0;
}
