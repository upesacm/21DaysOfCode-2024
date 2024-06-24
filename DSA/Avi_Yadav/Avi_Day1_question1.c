#include <stdio.h>

int count_valid_segments(int candy[], int n, int day, int month) {
    int count = 0;
    for (int i = 0; i <= n - month; i++) {
        int sum = 0;
        for (int j = 0; j < month; j++) {
            sum += candy[i + j];
        }
        if (sum == day) {
            count++;
        }
    }
    return count;
}

int main() {
    int n, day, month;

    // Taking input for the size of the array
    printf("Enter the number of candy squares: ");
    scanf("%d", &n);

    // Declaring the array
    int candy[n];

    // Taking input for the elements of the array
    printf("Enter the numbers on the candy squares: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &candy[i]);
    }

    // Taking input for Raju's birth day and month
    printf("Enter Raju's birth day: ");
    scanf("%d", &day);
    printf("Enter Raju's birth month: ");
    scanf("%d", &month);

    // Calculating the number of valid segments
    int result = count_valid_segments(candy, n, day, month);
    
    // Outputting the result
    printf("Number of valid ways to divide the bar: %d\n", result);

    return 0;
}
