#include <stdio.h>

int maxEqualStacks(int* stack1, int stack1Size, int* stack2, int stack2Size, int* stack3, int stack3Size){
    int sum1 = 0, sum2 = 0, sum3 = 0;
    for(int i = 0; i < stack1Size; i++) sum1 += stack1[i];
    for(int i = 0; i < stack2Size; i++) sum2 += stack2[i];
    for(int i = 0; i < stack3Size; i++) sum3 += stack3[i];
    
    while(sum1 != sum2 || sum2 != sum3){
        if(sum1 >= sum2 && sum1 >= sum3) sum1 -= stack1[--stack1Size];
        if(sum2 >= sum1 && sum2 >= sum3) sum2 -= stack2[--stack2Size];
        if(sum3 >= sum1 && sum3 >= sum2) sum3 -= stack3[--stack3Size];
    }
    
    return sum1;
}

int main(){
    int stack1[] = {3, 2, 1, 1, 1};
    int stack2[] = {4, 3, 2};
    int stack3[] = {1, 1, 4, 1};
    int stack1Size = sizeof(stack1) / sizeof(stack1[0]);
    int stack2Size = sizeof(stack2) / sizeof(stack2[0]);
    int stack3Size = sizeof(stack3) / sizeof(stack3[0]);
    
    printf("%d\n", maxEqualStacks(stack1, stack1Size, stack2, stack2Size, stack3, stack3Size));
    
    return 0;
}
