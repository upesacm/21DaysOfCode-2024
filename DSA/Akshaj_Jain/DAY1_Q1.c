#include <stdio.h>

int countSegments(int arr[], int n, int birthDay, int birthMonth) {
    int count = 0;

    for (int i = 0; i <= n - birthMonth; i++) {
        int sum = 0;

        for (int j = 0; j < birthMonth; j++) {
            sum += arr[i + j];
        }

        if (sum == birthDay) {
            count++;
        }
    }

    return count;
}

int main() {
    int arr[] = {2,2,1,3,2};
    int birthDay = 4;
    int birthMonth = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countSegments(arr, n, birthDay, birthMonth);
    printf("Number of valid ways to divide the bar: %d\n", result);

    return 0;
}
