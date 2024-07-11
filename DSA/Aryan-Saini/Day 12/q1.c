#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        printf("Input must be a positive integer\n");
        return -1; 
    } else if (n == 1) {
        return 1; 
    } else if (n == 2) {
        return 1; 
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    int result = fibonacci(n);
    if (result != -1) { 
        printf("The %d-th Fibonacci number is: %d\n", n, result);
    }
    
    return 0;
}
