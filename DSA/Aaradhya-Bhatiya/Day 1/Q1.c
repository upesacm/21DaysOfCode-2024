#include <stdio.h>

int main() {
    int candy[20];
    int day, month, i = 0, suc_comb = 0, sum = 0, iter = 0, n;

    // Input candies
    printf("Enter the number of candies: ");
    scanf("%d", &n);

    printf("candy = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &candy[i]);
    }

    // Input day and month
    printf("day = ");
    scanf("%d", &day);
    printf("month = ");
    scanf("%d", &month);

    // Main loop
    for (iter = 0; iter <= n - month; iter++) {
        sum = 0;
        for (i = iter; i < iter + month; i++) {
            sum += candy[i];
        }
        if (sum == day) {
            suc_comb++;
        }
    }

    // Output
    printf("%d\n", suc_comb);

    return 0;
}
