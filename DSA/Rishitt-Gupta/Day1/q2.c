#include <stdio.h>
int main() {
    int a;
    //size of array
    scanf("%d",&a);
    int arr[a];
    //elements of array
    for (int i = 0; i < a; i++)
    {
        scanf("%d",arr[i]);
    }
    //element which will divide the sum
    int k = scanf("%d",&k);
    //the output variable
    int count = 0;

    //iterating loop for possible pairs with required conditions
    for(int i = 0; i < a; i++) {
        for(int j = i + 1; j < a; j++) {
            if ((i < j) && ((arr[i] + arr[j]) % k == 0)) {
                count++;
            }
        }
    }
    printf("Answer: %d\n", count);
    return 0;
}
