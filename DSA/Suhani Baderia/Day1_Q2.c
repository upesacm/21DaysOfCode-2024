#include <stdio.h>

int pairs(int arr[], int n, int k) {
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int arr[] = {1, 3, 2, 6, 1, 2};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = pairs(arr, n, k);
    printf("Number of valid pairs: %d\n", result);

    return 0;
}
