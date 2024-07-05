#include <stdio.h>

int reverseNumber(int num, int temp) {
    if (num == 0) {
        return temp;
    }
    temp = (temp * 10) + (num % 10);
    return reverseNumber(num / 10, temp);
}

const char* isPalindrome(int num) {
    if (num < 0) {
        return "NO";
    }
    if (num == reverseNumber(num, 0)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("%s\n", isPalindrome(number));
    return 0;
}
