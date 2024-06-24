#include <stdio.h>

int countWays(int arr[], int n, int d, int m) {
    int count = 0;

    // Iterate through the array
    for (int i = 0; i <= n - m; i++) {
        int sum = 0;
        
        // Calculate the sum of the current segment
        for (int j = 0; j < m; j++) {
            sum += arr[i + j];
        }

        // Check if the sum matches the birth day
        if (sum == d) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    
    printf("Enter the number of squares: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the numbers on the squares: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int d, m;
    printf("Enter Raju's birth day and month: ");
    scanf("%d %d", &d, &m);
    
    int result = countWays(arr, n, d, m);
    printf("Number of ways to divide the bar: %d\n", result);
    
    return 0;
}
ṇṇ
