#include <stdio.h>
int sum(int stack[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += stack[i];
    }
    return total;
}
int main() {
    int n1, n2, n3;
    printf("Enter the number of cylinders in stack 1: ");
    scanf("%d", &n1);
    int stack1[n1];
    printf("Enter the heights of the cylinders in stack 1: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &stack1[i]);
    }
    printf("Enter the number of cylinders in stack 2: ");
    scanf("%d", &n2);
    int stack2[n2];
    printf("Enter the heights of the cylinders in stack 2: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &stack2[i]);
    }
    printf("Enter the number of cylinders in stack 3: ");
    scanf("%d", &n3);
    int stack3[n3];
    printf("Enter the heights of the cylinders in stack 3: ");
    for (int i = 0; i < n3; i++) {
        scanf("%d", &stack3[i]);
    }
    int sum1 = sum(stack1, n1);
    int sum2 = sum(stack2, n2);
    int sum3 = sum(stack3, n3);

    int i1 = 0, i2 = 0, i3 = 0;
    while (i1 < n1 && i2 < n2 && i3 < n3) {
        if (sum1 == sum2 && sum2 == sum3) {
            printf("The maximum possible height where all stacks are equal is: %d\n", sum1);
            return 0;
        }
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stack1[i1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stack2[i2++];
        } else if (sum3 >= sum1 && sum3 >= sum2) {
            sum3 -= stack3[i3++];
        }
    }
    printf("The maximum possible height where all stacks are equal is: 0\n");
    return 0;
}
