#include <stdio.h>

#define MAX_STACK_HEIGHT 1000

int findMaxEqualHeight(int stack1[], int size1, int stack2[], int size2, int stack3[], int size3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int i;


    for (i = 0; i < size1; i++) sum1 += stack1[i];
    for (i = 0; i < size2; i++) sum2 += stack2[i];
    for (i = 0; i < size3; i++) sum3 += stack3[i];

   
    int top1 = 0, top2 = 0, top3 = 0;

 
    while (top1 < size1 && top2 < size2 && top3 < size3) {
       
        if (sum1 == sum2 && sum3 == sum2) {
            return sum1;
        }

 
        if (sum1 >= sum2 && sum1 >= sum3) {
            sum1 -= stack1[top1++];
        } else if (sum2 >= sum1 && sum2 >= sum3) {
            sum2 -= stack2[top2++];
        } else {
            sum3 -= stack3[top3++];
        }
    }

    return 0;
}

int main() {
    int size1, size2, size3;
    printf("Enter the number of cylinders in stack1: ");
    scanf("%d", &size1);
    int stack1[size1];
    printf("Enter the heights of cylinders in stack1: ");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &stack1[i]);
    }

    printf("Enter the number of cylinders in stack2: ");
    scanf("%d", &size2);
    int stack2[size2];
    printf("Enter the heights of cylinders in stack2: ");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &stack2[i]);
    }

    printf("Enter the number of cylinders in stack3: ");
    scanf("%d", &size3);
    int stack3[size3];
    printf("Enter the heights of cylinders in stack3: ");
    for (int i = 0; i < size3; i++) {
        scanf("%d", &stack3[i]);
    }

    int maxHeight = findMaxEqualHeight(stack1, size1, stack2, size2, stack3, size3);
    printf("The maximum possible height where all stacks are equal is: %d\n", maxHeight);

    return 0;
}
 
