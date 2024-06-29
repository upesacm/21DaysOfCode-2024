#include <stdio.h>

int getSum(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int height(int *s1, int size1, int *s2, int size2, int *s3, int size3) {
    int sum1 = getSum(s1, size1);
    int sum2 = getSum(s2, size2);
    int sum3 = getSum(s3, size3);

    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2 && k < size3) {
        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }

        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= s1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= s2[j++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= s3[k++];
        }
    }

    return 0;
}

int main() {
    int s1[] = {3, 2, 1, 1, 1};
    int s2[] = {4, 3, 2};
    int s3[] = {1, 1, 4, 1};

    int size1 = sizeof(s1) / sizeof(s1[0]);
    int size2 = sizeof(s2) / sizeof(s2[0]);
    int size3 = sizeof(s3) / sizeof(s3[0]);

    int result = height(s1, size1, s2, size2, s3, size3);

    printf("The maximum possible height is: %d\n", result);

    return 0;
}
