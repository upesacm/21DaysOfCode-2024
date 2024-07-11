#include <stdio.h>

int break_candy(int arr[], int n, int month, int date) {
    int count = 0;
    for (int i = 0; i <= n - month; i++) {
        int sum = 0;
        for (int j = i; j < i + month; j++) {
            sum += arr[j];
        }
        if (sum == date) {
            count++;
        }
        if (sum>date){
            break;
        }
    }
    return count;
}

int main() {
   int n,month,date;

    printf("Enter size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter birth month:");
    scanf("%d", &month);

    printf("Enter birth date:");
    scanf("%d", &date);

    int ways = break_candy(arr, n, month, date);
    printf("Number of ways to break the candy: %d\n", ways);

    return 0;
}