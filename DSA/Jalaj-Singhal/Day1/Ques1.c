#include <stdio.h>
int count(int candy[], int d, int mon, int n) {
    int count = 0, sum = 0;
    for (int i = 0; i <= n - mon; i++) {
        for (int j = 0; j < mon; j++) {
            sum += candy[i+j];
        }
        if (sum == d) {
            count++;
        }
    }
    return count;
}
int main() {
    int n, d, mon;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int candy[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &candy[i]);
    }
    printf("Enter birth day: ");
    scanf("%d", &d);
    printf("Enter birth month: ");
    scanf("%d", &mon);
    int result = count(candy, n, d, mon);
    printf("\nNumber of ways to divide the bar: %d", result);
    return 0;
}
