#include <stdio.h>
int sumDigits(int num) {
    if (num < 10) {
        return num;
    } else {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sumDigits(sum);
    }
}
int main() {
    int number;
    printf("Enter a large integer: ");
    scanf("%d", &number);
    int result = sumDigits(number);
    printf("The single digit result is: %d\n", result);  
    return 0;
}
