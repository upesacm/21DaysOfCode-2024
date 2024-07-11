#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool isPalindromeHelper(const char* str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindromeHelper(str, start + 1, end - 1);
}
bool isPalindrome(int num) {
    char str[20];
    sprintf(str, "%d", num); 
    int len = strlen(str);
    return isPalindromeHelper(str, 0, len - 1);
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (isPalindrome(number)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
