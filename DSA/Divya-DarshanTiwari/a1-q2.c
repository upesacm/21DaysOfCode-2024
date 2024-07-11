#include <stdio.h>

int divisibleSumPairs(int nums[], int n, int k) {
    int count[100] = {0}; // assuming k is less than 100
    int pairs = 0;
    for (int i = 0; i < n; i++) {
        int remainder = nums[i] % k;
        pairs += count[(k - remainder) % k];
        count[remainder]++;
    }
    return pairs;
}

int main() {
    int n;
    printf("Enter size : ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int k;
    printf("Enter value of k : ");
    scanf("%d", &k);
    printf("Output = %d\n", divisibleSumPairs(nums, n, k));
    return 0;
}