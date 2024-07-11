#include <stdio.h>
int sum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}
int maxEqualHeight(int stack1[], int size1, int stack2[], int size2, int stack3[], int size3) {
    int sum1 = sum(stack1, size1);
    int sum2 = sum(stack2, size2);
    int sum3 = sum(stack3, size3);

    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2 && k < size3) {
        if (sum1 == sum2 && sum2 == sum3) {
            return sum1;
        }
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stack1[i++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stack2[j++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= stack3[k++];
        }
    }

    return 0; 
}

int main() {
    int stack1[] = {3, 2, 1, 1, 1};
    int stack2[] = {4, 3, 2};
    int stack3[] = {1, 1, 4, 1};

    int size1 = sizeof(stack1) / sizeof(stack1[0]);
    int size2 = sizeof(stack2) / sizeof(stack2[0]);
    int size3 = sizeof(stack3) / sizeof(stack3[0]);

    int result = maxEqualHeight(stack1, size1, stack2, size2, stack3, size3);
    printf("The maximum possible height where all stacks are equal is: %d\n", result);

    return 0;
}
