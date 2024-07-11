#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int numDigits(int num) {
    int count = 0;
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}


bool isPalindromeHelper(int num, int *factor) {
    if (num == 0) {
        return true;
    }

    int leading = num / *factor;
    int trailing = num % 10;
    if (leading != trailing) {
        return false;
    }

    num = (num % *factor) / 10;
    *factor /= 100;

    return isPalindromeHelper(num, factor);
}

bool isPalindrome(int num) {
    if (num < 0) {
        num = -num;  
    }

    int factor = 1;
    for (int i = 1; i < numDigits(num); ++i) {
        factor *= 10;
    }

    return isPalindromeHelper(num, &factor);
}

int main() {
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);

    if (isPalindrome(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
