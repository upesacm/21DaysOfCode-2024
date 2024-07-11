#include <stdio.h>

int find_max_height(int stack1[], int stack2[], int stack3[], int n1, int n2, int n3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for (int i = 0; i < n1; i++) {
        sum1 += stack1[i];
    }
    for (int i = 0; i < n2; i++) {
        sum2 += stack2[i];
    }
    for (int i = 0; i < n3; i++) {
        sum3 += stack3[i];
    }

    int min_sum = sum1;
    if (sum2 < min_sum) {
        min_sum = sum2;
    }
    if (sum3 < min_sum) {
        min_sum = sum3;
    }

    int height = 0;
    while (sum1 > min_sum || sum2 > min_sum || sum3 > min_sum) {
        if (sum1 > min_sum) {
            sum1 -= stack1[--n1];
        }
        if (sum2 > min_sum) {
            sum2 -= stack2[--n2];
        }
        if (sum3 > min_sum) {
            sum3 -= stack3[--n3];
        }
        min_sum = sum1;
        if (sum2 < min_sum) {
            min_sum = sum2;
        }
        if (sum3 < min_sum) {
            min_sum = sum3;
        }
        height++;
    }

    return height;
}

int main() {
    int n1, n2, n3;
    printf("Enter the number of cylinders in stack 1: ");
    scanf("%d", &n1);
    int stack1[n1];
    printf("Enter the heights of cylinders in stack 1: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &stack1[i]);
    }

    printf("Enter the number of cylinders in stack 2: ");
    scanf("%d", &n2);
    int stack2[n2];
    printf("Enter the heights of cylinders in stack 2: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &stack2[i]);
    }

    printf("Enter the number of cylinders in stack 3: ");
    scanf("%d", &n3);
    int stack3[n3];
    printf("Enter the heights of cylinders in stack 3: ");
    for (int i = 0; i < n3; i++) {
        scanf("%d", &stack3[i]);
    }

    int max_height = find_max_height(stack1, stack2, stack3, n1, n2, n3);
    printf("The maximum possible height where all stacks are equal is: %d\n", max_height);

    return 0;
}
