#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if a given string is a palindrome
bool isPalindrome(char *s, int length) {
    for (int i = 0; i < length / 2; i++) {
        if (s[i] != s[length - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to add a substring to the list of distinct palindromic substrings if it is not already present
bool addDistinctSubstring(char **substrings, int *count, char *substring) {
    for (int i = 0; i < *count; i++) {
        if (strcmp(substrings[i], substring) == 0) {
            return false;
        }
    }
    substrings[*count] = (char *)malloc((strlen(substring) + 1) * sizeof(char));
    strcpy(substrings[*count], substring);
    (*count)++;
    return true;
}

// Function to find the number of distinct palindromic substrings
int countDistinctPalindromicSubstrings(char *s) {
    int n = strlen(s);
    char **substrings = (char **)malloc(n * n * sizeof(char *));
    int count = 0;

    for (int length = 1; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            char substring[length + 1];
            strncpy(substring, s + i, length);
            substring[length] = '\0';

            if (isPalindrome(substring, length)) {
                addDistinctSubstring(substrings, &count, substring);
            }
        }
    }

    // Free the allocated memory
    for (int i = 0; i < count; i++) {
        free(substrings[i]);
    }
    free(substrings);

    return count;
}

int main() {
    char s[] = "aabbcc";
    int resultCount = countDistinctPalindromicSubstrings(s);

    printf("Number of distinct palindromic substrings: %d\n", resultCount);

    return 0;
}
