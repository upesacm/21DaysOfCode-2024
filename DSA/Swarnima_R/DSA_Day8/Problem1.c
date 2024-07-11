/*
Question 1: You have three stacks of cylinders with varying heights. Remove cylinders from the top of the stacks so that all stacks are of the same height, and return this maximum possible height.

Inputs:
Three arrays of integers representing the heights of cylinders in each stack.
Output:
• The maximum possible height where all stacks are equal.
*/

#include <stdio.h>
#include <stdlib.h>

int sum(int stack[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += stack[i];
    }
    return total;
}

int max_equal_height(int stack1[], int size1, int stack2[], int size2, int stack3[], int size3) {
    int total1 = sum(stack1, size1);
    int total2 = sum(stack2, size2);
    int total3 = sum(stack3, size3);

    int i1 = 0, i2 = 0, i3 = 0;

    while (1) {
        if (total1 == total2 && total2 == total3) {
            return total1;
        }

        if (i1 == size1 || i2 == size2 || i3 == size3) {
            return 0;
        }

        if (total1 >= total2 && total1 >= total3) {
            total1 -= stack1[i1++];
        } else if (total2 >= total1 && total2 >= total3) {
            total2 -= stack2[i2++];
        } else if (total3 >= total1 && total3 >= total2) {
            total3 -= stack3[i3++];
        }
    }
}

int main() {
    int size1, size2, size3;

    printf("Enter the number of cylinders in stack 1: ");
    scanf("%d", &size1);
    int *stack1 = (int *)malloc(size1 * sizeof(int));
    printf("Enter the heights of the cylinders in stack 1: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &stack1[i]);
    }

    printf("Enter the number of cylinders in stack 2: ");
    scanf("%d", &size2);
    int *stack2 = (int *)malloc(size2 * sizeof(int));
    printf("Enter the heights of the cylinders in stack 2: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &stack2[i]);
    }

    printf("Enter the number of cylinders in stack 3: ");
    scanf("%d", &size3);
    int *stack3 = (int *)malloc(size3 * sizeof(int));
    printf("Enter the heights of the cylinders in stack 3: ");
    for (int i = 0; i < size3; i++) {
        scanf("%d", &stack3[i]);
    }

    int result = max_equal_height(stack1, size1, stack2, size2, stack3, size3);

    printf("Maximum possible height where all stacks are equal: %d\n", result);

    free(stack1);
    free(stack2);
    free(stack3);

    return 0;
}
