#include<stdio.h>
int re(int arr[], int n, int k) {
    int count = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    return count;
}
int main() {
    int n, k;
    printf("Enter the size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    int result = re(arr, n, k);
    printf("Pair: %d", result);
    return 0;
}
