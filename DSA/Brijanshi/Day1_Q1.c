#include <stdio.h>

int count_ways(int candy[], int n, int day, int month) {
    int count = 0;
    for (int i = 0; i <= n - month; i++) {
        int sum = 0;
        for (int j = i; j < i + month; j++) {
            sum += candy[j];
        }
        if (sum == day) {
            count++;
        }
    }
    return count;
}

int main() {
    int candy[] = {2, 2, 1, 3, 2};
    int n = sizeof(candy) / sizeof(candy[0]);
    int day = 4;
    int month = 2;
    int ways = count_ways(candy, n, day, month);
    printf("Number of valid ways: %d\n", ways);
    return 0;
}
