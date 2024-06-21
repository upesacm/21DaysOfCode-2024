/*
Swarnima Bisht
500105696

Given an array of integers and an integer k, determine the number of (i, j) pairs where i < j and the sum of the pair is divisible by k.

Inputs:
An array of integers.

An integer k.

Output:
The number of valid (i, j) pairs.

*/

#include <stdio.h>
#include <stdlib.h>

int countPairs(int *arr,int n,int k);

int main()
{
    int n;
        printf("Enter the number of elements in array = ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("NO MEMORY ALLOCATED\n");
        return 1;
    }

    printf("Enter the elements of the array = ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    return 0;

    int k;
    printf("Enter the number the array pair sum should be divisible by = ");
    scanf("%d",&k);

    printf("Number of divisible pairs = %d",countPairs(arr,n,k));

}


int countPairs(int *arr,int n,int k){
    
}