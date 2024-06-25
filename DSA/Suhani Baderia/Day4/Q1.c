#include <stdio.h>
#include <string.h>

int palindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

int substring(char* str, int length) {
    int str_len = strlen(str);
    if (length > str_len) return 0;

    char substring[100];
    int count = 0;

    for (int i = 0; i <= str_len - length; i++) {
        if (palindrome(str, i, i + length - 1)) {
            strncpy(substring, &str[i], length);
            substring[length] = '\0';
            int distinct = 1;

            for (int j = 0; j < i; j++) {
                if (strncmp(&str[j], substring, length) == 0 && palindrome
    (str, j, j + length - 1)) {
                    distinct = 0;
                    break;
                }
            }
            if (distinct) count++;
        }
    }
    
    return count;
}

int main() {
    char str[] = "ababa";
    int length = 3;
    int result = substring
(str, length);
    printf("Number of distinct palindromic substrings of length %d: %d\n", length, result);
    return 0;
}
