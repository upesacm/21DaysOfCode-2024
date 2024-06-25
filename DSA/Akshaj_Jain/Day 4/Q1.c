#include <stdio.h>
#include <string.h>

int is_palindrome(const char* str, int start, int length) {
    int end = start + length - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

int is_distinct_palindrome(char palindromes[][50], int count, const char* str, int length) {
    for (int i = 0; i < count; i++) {
        if (strncmp(palindromes[i], str, length) == 0) {
            return 0;
        }
    }
    return 1;
}

int count_distinct_palindromic_substrings(const char* str, int length) {
    int str_len = strlen(str);
    if (length > str_len) {
        return 0; 
    }

    char palindromes[100][50];  
    int count = 0;  

    for (int i = 0; i <= str_len - length; i++) {
        if (is_palindrome(str, i, length)) {
            if (is_distinct_palindrome(palindromes, count, str + i, length)) {
                strncpy(palindromes[count], str + i, length);
                palindromes[count][length] = '\0';
                count++;
            }
        }
    }

    return count;
}

int main() {
    const char* string = "ababa";
    int length = 3;
    int result = count_distinct_palindromic_substrings(string, length);
    printf("Number of distinct palindromic substrings of length %d: %d\n", length, result);
    return 0;
}
