#include <stdio.h>
#include <string.h>

int is_palindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int count_palindromic_substrings(char* str, int len) {
    int str_len = strlen(str);
    if (len > str_len) return 0;

    char temp[100];
    int distinct_count = 0;

    for (int i = 0; i <= str_len - len; i++) {
        if (is_palindrome(str, i, i + len - 1)) {
            strncpy(temp, &str[i], len);
            temp[len] = '\0';
            int is_new = 1;
            
            for (int j = 0; j < i; j++) {
                if (strncmp(&str[j], temp, len) == 0 && is_palindrome(str, j, j + len - 1)) {
                    is_new = 0;
                    break;
                }
            }
            if (is_new) distinct_count++;
        }
    }
    
    return distinct_count;
}

int main() {
    char str[] = "ababa";
    int len = 3;
    int result = count_palindromic_substrings(str, len);
    printf("No. of palindromic substrings of length %d: %d\n", len, result);
    return 0;
}
