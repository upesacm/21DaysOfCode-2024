#include <stdio.h>

int digitSum(int num) {
    if (num < 10) {
        return num;
    } else {
        int total = 0;
        while (num > 0) {
            total += num % 10;
            num /= 10;
        }
        return digitSum(total);
    }
}
int main() {
    int inputNumber = 9875;
    printf("The final digit is: %d\n", digitSum(inputNumber));
    return 0;
}
