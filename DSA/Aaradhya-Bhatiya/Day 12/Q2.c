#include <stdio.h>

unsigned long long sumDigits(unsigned long long num) {
    if (num < 10) {
        return num;
    }
    unsigned long long sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sumDigits(sum);
}

int main() {
    unsigned long long num;

    printf("Enter number: ");
    scanf("%llu", &num);

    unsigned long long result = sumDigits(num);
    printf("Result = %llu\n", result);

    return 0;
}
