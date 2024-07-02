#include <stdio.h>

int recSumDigits(int n);

int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);

    printf("Single digit obtained after recursive sum : %d",recSumDigits(n));
    return 0;
}

int recSumDigits(int n){
    if(n<10){
        return n;
    }
    int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return recSumDigits(sum);
}