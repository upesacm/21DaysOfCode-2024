/*
Swarnima Bisht
500105696

Question 1:

Rohan and Raju have a candy where each square has a number. Rohan wants to find out how many ways she can break the bar into a contiguous segment such that:

The segment length matches Raju's birth month.
The sum of the numbers in the segment equals Raju's birth day.
Inputs:
An array of integers representing the chocolate squares.

Two integers representing Raju's birth day and birth month.

Output:
The number of valid ways to divide the bar.

*/

#include <stdio.h>
#include <stdlib.h>

int countSegments(int *candy,int n, int day, int month);

int main() {
    int n, day, month;

    printf("Enter the number of elements in the candy array = ");
    scanf("%d", &n);

    int* candy = (int*)malloc(n * sizeof(int));

    if (candy == NULL) {
        printf("NO MEMORY ALLOCATED\n");
        return 1;
    }

    printf("Enter the elements of the candy array = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &candy[i]);
    }

    printf("Enter Birthday = ");
    scanf("%d", &day);
    printf("Enter Birth month = ");
    scanf("%d", &month);

    int result = countSegments(candy,n, day, month);
    printf("Number of valid segments = %d\n", result);

    free(candy);

    return 0;
}

int countSegments(int *candy,int n, int day, int month) {
    int count = 0;

    for (int i = 0; i <= n - month; i++) {
        int sum = 0;
        for (int j = 0; j < month; j++) {
            sum += candy[i + j];
        }
        if (sum == day) {
            count += 1;
        }
    }

    return count;
}

