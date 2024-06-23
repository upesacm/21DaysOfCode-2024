#include <stdio.h>

// Function to count the valid segments
int countValidSegments(int candy[], int n, int day, int month) {
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
    int candy[] = {2, 2, 1, 3, 2};
    int day = 4;
    int month = 2;
    int n = sizeof(candy) / sizeof(candy[0]);

    int result = countValidSegments(candy, n, day, month);
    printf("Number of valid segments: %d\n", result);  // Output: 2

    return 0;
}

