#include <stdio.h>

int countPairs(int arr[], int size, int k) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((arr[i] + arr[j]) % k == 0) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    printf("Enter the length of the array: ");
    int size;
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    int result = countPairs(arr, size, k);
    printf("Number of valid pairs: %d\n", result);
    
    return 0;
}
