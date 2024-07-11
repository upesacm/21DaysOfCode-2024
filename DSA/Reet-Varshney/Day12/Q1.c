#include <stdio.h>

int calculateFib(int num) {
    if (num <= 1) {
        return num;
    } else {
        return calculateFib(num-1) + calculateFib(num-2);
    }
}
int main() {
    int userInput = 5;
    printf("The Fibonacci number at position %d is: %d\n", userInput, calculateFib(userInput));
    return 0;
}
