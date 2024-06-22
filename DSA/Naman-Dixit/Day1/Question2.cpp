#include <stdio.h>

// Function to count pairs with sum divisible by k
int countDivisiblePairs(int arr[], int n, int k) {
    // Array to count frequencies of remainders
    int remainderCount[k];
    for (int i = 0; i < k; i++) {
        remainderCount[i] = 0;
    }

    // Fill remainder count array
    for (int i = 0; i < n; i++) {
        remainderCount[arr[i] % k]++;
    }

    // Calculate the number of valid pairs
    int count = 0;

    // Count pairs with remainder 0
    count += (remainderCount[0] * (remainderCount[0] - 1)) / 2;

    // Count pairs with remainders that add up to k
    for (int i = 1; i <= k/2 && i != (k - i); i++) {
        count += remainderCount[i] * remainderCount[k - i];
    }

    // Special case for when k is even
    if (k % 2 == 0) {
        count += (remainderCount[k / 2] * (remainderCount[k / 2] - 1)) / 2;
    }

    return count;
}

// Driver code
int main() {
    printf("enter size\n");
     int n;
     scanf("%d", &n);
    printf("enter array\n");
    int arr[n];
  
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i] );
    }
    printf("enter number for operation\n");
    int k;
    scanf("%d", &k);
    
    int result = countDivisiblePairs(arr, n, k);
    printf("Number of pairs: %d\n", result);

    return 0;
}
8
