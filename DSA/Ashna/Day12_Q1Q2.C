//Q1

#include <stdio.h>
int fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter an integer n: ");
    scanf("%d", &n);
    printf("The %d-th Fibonacci number is: %d\n", n, fibonacci(n));
    return 0;
}

//Q2

#include <stdio.h>
int sumOfDigits(int num) {
    // Base case: if the number is a single digit, return it
    if (num < 10) {
        return num;
    }
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sumOfDigits(sum);
}

int main() {
    int number;
    printf("Enter a large integer: ");
    scanf("%d", &number);
    printf("The single digit result is: %d\n", sumOfDigits(number));
    return 0;
}
