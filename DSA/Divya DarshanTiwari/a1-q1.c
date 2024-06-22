#include <stdio.h>

int countPairsWith(int arr[], int n, int k) {
    int count = 0;
    int freq[k];
    for (int i = 0; i < k; i++) {
        freq[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        freq[arr[i] % k]++;
    }
    count += freq[0] * (freq[0] - 1) / 2;
    for (int i = 1; i <= k / 2; i++) {
        count += freq[i] * freq[k - i];
    }
    if (k % 2 == 0) {
        count += freq[k / 2] * (freq[k / 2] - 1) / 2;
    }
    return count;
}

int main() {
    int arr[] = {1, 3, 2, 6, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    printf("Output: %d\n", countPairsWith(arr, n, k));
    return 0;
}
