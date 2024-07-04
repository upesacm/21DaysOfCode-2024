#include <stdio.h>

int reverse(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    rev = rev * 10 + num % 10;
    return reverse(num / 10, rev);
}

int isPalindrome(int num) {
    int rev = reverse(num, 0);
    return num == rev;
}

char* checkPalindrome(int num) {
    if (isPalindrome(num)) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int number = 121;
    printf("%s\n", checkPalindrome(number));
    return 0;
}
