#include <stdio.h>
#include <stdlib.h>

int maxEqualHeight(int st1[], int s1, int st2[], int s2, int st3[], int s3) {
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int top1 = 0, top2 = 0, top3 = 0;
    for (int i = 0; i < s1; i++) {
        sum1 += st1[i];
    }
    for (int i = 0; i < s2; i++) {
        sum2 += st2[i];
    }
    for (int i = 0; i < s3; i++) {
        sum3 += st3[i];
    }
    while (1) {
        if (top1 >= s1 || top2 >= s2 || top3 >= s3){
            return 0;
        }
        if (sum1 == sum2 && sum2 == sum3){
            return sum1;
        }
        if (sum1 >= sum2 && sum1 >= sum3){
            sum1 -= st1[top1++];
        }
        else if (sum2 >= sum1 && sum2 >= sum3){
            sum2 -= st2[top2++];
        }
        else if (sum3 >= sum1 && sum3 >= sum2){
            sum3 -= st3[top3++];
        }
    }
}

int main() {
    int st1[100], st2[100], st3[100];
    int s1, s2, s3;

    printf("Enter the number of elements in stack 1: ");
    scanf("%d", &s1);
    printf("Enter %d elements for stack 1: ", s1);
    for (int i = 0; i < s1; ++i) {
        scanf("%d", &st1[i]);
    }

    printf("Enter the number of elements in stack 2: ");
    scanf("%d", &s2);
    printf("Enter %d elements for stack 2: ", s2);
    for (int i = 0; i < s2; ++i) {
        scanf("%d", &st2[i]);
    }

    printf("Enter the number of elements in stack 3: ");
    scanf("%d", &s3);
    printf("Enter %d elements for stack 3: ", s3);
    for (int i = 0; i < s3; ++i) {
        scanf("%d", &st3[i]);
    }

    int result = maxEqualHeight(st1, s1, st2, s2, st3, s3);
    printf("Maximum possible equal height for all stacks: %d\n", result);

    return 0;
}
