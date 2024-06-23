#include <stdio.h>
int count(int arr[], int n, int day, int month) {
    int count = 0;
    for (int i = 0; i <= n - month; i++) {
        int sum = 0;
        for (int j = 0; j < month; j++) {
            sum += arr[i + j];
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
    int result = count(candy, n, day, month);
    printf("Number of valid ways to divide the bar: %d\n", result);

    return 0;
}

