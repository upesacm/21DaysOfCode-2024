#include <stdio.h>

int count_pairs(int arr[], int n, int k) {
    int count[k];
    for (int i = 0; i < k; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i] % k]++;
    }
    int pairs = 0;
    for (int i = 0; i <= k / 2; i++) {
        if (i == 0 || i == k / 2) {
            pairs += count[i] * (count[i] - 1) / 2;
        } else {
            pairs += count[i] * count[k - i];
        }
    }
    return pairs;
}

int main() {
    int arr[] = {1, 3, 2, 6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int pairs = count_pairs(arr, n, k);
    printf("Number of valid pairs: %d\n", pairs);
    return 0;
}
