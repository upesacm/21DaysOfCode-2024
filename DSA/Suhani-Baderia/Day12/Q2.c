#include <stdio.h>

int sumDigits(int n) {
    if (n < 10) {
        return n;
    } else {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sumDigits(sum);
    }
}

int main() {
    int number = 9875;
    printf("The single digit result is: %d\n", sumDigits(number));
    return 0;
}
