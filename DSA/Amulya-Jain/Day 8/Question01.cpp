#include <stdio.h>

int calculateHeight(int stack[], int size) {
    int height = 0;
    for (int i = 0; i < size; i++) {
        height += stack[i];
    }
    return height;
}

int maxEqualHeight(int stack1[], int size1, int stack2[], int size2, int stack3[], int size3) {
    int h1 = calculateHeight(stack1, size1);
    int h2 = calculateHeight(stack2, size2);
    int h3 = calculateHeight(stack3, size3);

    int i1 = 0, i2 = 0, i3 = 0;

    while (true) {
        if (i1 == size1 || i2 == size2 || i3 == size3) {
            return 0;
        }


        if (h1 == h2 && h2 == h3) {
            return h1;
        }

        if (h1 >= h2 && h1 >= h3) {
            h1 -= stack1[i1++];
        } else if (h2 >= h1 && h2 >= h3) {
            h2 -= stack2[i2++];
        } else if (h3 >= h1 && h3 >= h2) {
            h3 -= stack3[i3++];
        }
    }
}

int main() {
    int stack1[] = {3, 2, 1, 1, 1};
    int size1 = sizeof(stack1) / sizeof(stack1[0]);

    int stack2[] = {4, 3, 2};
    int size2 = sizeof(stack2) / sizeof(stack2[0]);

    int stack3[] = {1, 1, 4, 1};
    int size3 = sizeof(stack3) / sizeof(stack3[0]);

    int result = maxEqualHeight(stack1, size1, stack2, size2, stack3, size3);
    printf("The maximum possible height where all stacks are equal is: %d\n", result);

    return 0;
}
