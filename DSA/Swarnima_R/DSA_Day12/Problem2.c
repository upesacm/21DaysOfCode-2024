#include <stdio.h>

long long int recSumDigits(long long int n);

long long int main(){
    long long int n;
    printf("Enter the number : ");
    scanf("%llu",&n);

    printf("Single digit obtained after recursive sum : %llu",recSumDigits(n));
    return 0;
}
long long int recSumDigits(long long int n){
    if(n<10){
        return n;
    }
    long long int sum = 0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return recSumDigits(sum);
}