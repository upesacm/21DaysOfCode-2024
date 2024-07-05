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
    return isPalindrome(num)? "YES" : "NO";
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("%s\n", checkPalindrome(num));

    return 0;
}