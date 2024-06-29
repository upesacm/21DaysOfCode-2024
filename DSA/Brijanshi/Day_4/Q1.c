#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char* str, int len) {
    int start = 0;
    int end = len - 1;
    while (start < end) {
        if (str[start]!= str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int count_palindromic_substrings(char* str, int len, int substring_len) {
    int count = 0;
    bool seen[1000]; // assuming max substring length is 1000
    memset(seen, false, sizeof(seen));

    for (int i = 0; i <= strlen(str) - substring_len; i++) {
        char substring[substring_len + 1];
        strncpy(substring, str + i, substring_len);
        substring[substring_len] = '\0';

        if (is_palindrome(substring, substring_len) &&!seen[i]) {
            count++;
            for (int j = i; j < i + substring_len; j++) {
                seen[j] = true;
            }
        }
    }

    return count;
}

int main() {
    char str[] = "ababa";
    int length = 3;
    int count = count_palindromic_substrings(str, length, length);
    printf("Number of distinct palindromic substrings of length %d: %d\n", length, count);
    return 0;
}
