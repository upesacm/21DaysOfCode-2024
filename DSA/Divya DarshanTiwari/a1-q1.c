#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter elements : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int day, month, count = 0;
    printf("Enter day and month : ");
    scanf("%d %d", &day, &month);
    for(int i = 0; i <= n - month; i++) {
        int sum = 0;
        for(int j = i; j < i + month; j++) {
            sum += arr[j];
        }
        if(sum == day) count++;
    }
    printf("Unique ways : %d\n", count);
    free(arr);
    return 0;
}
