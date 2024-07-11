#include <stdio.h>
#include <stdlib.h>

int max_height(int stack1[], int stack2[], int stack3[], int n1, int n2, int n3) {
    // Calculate the total number of cylinders
    int total = n1 + n2 + n3;

    // Calculate the sum of the heights of all cylinders
    int sum = 0;
    for (int i = 0; i < n1; i++) {
        sum += stack1[i];
    }
    for (int i = 0; i < n2; i++) {
        sum += stack2[i];
    }
    for (int i = 0; i < n3; i++) {
        sum += stack3[i];
    }

    // Calculate the target height
    int target = sum / (total / 3);

    // Remove cylinders from the top of each stack until all stacks have the same height
    while (stack1[n1 - 1] != target || stack2[n2 - 1] != target || stack3[n3 - 1] != target) {
        // Remove a cylinder from the stack with the highest top cylinder
        if (stack1[n1 - 1] > stack2[n2 - 1] && stack1[n1 - 1] > stack3[n3 - 1]) {
            n1--;
        } else if (stack2[n2 - 1] > stack1[n1 - 1] && stack2[n2 - 1] > stack3[n3 - 1]) {
            n2--;
        } else {
            n3--;
        }
    }

    // Return the target height
    return target;
}

int main() {
    int stack1[] = {3, 2, 1, 1, 1};
    int stack2[] = {4, 3, 2};
    int stack3[] = {1, 1, 4, 1};

    int n1 = sizeof(stack1) / sizeof(stack1[0]);
    int n2 = sizeof(stack2) / sizeof(stack2[0]);
    int n3 = sizeof(stack3) / sizeof(stack3[0]);

    printf("Maximum possible height: %d\n", max_height(stack1, stack2, stack3, n1, n2, n3));

    return 0;
}