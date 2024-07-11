#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if a substring is palindromic
int is_palindrome(const char *str, int start, int length) {
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

// Function to find the number of distinct palindromic substrings of a specified length
int count_distinct_palindromic_substrings(char *str, int length) {
    int n = strlen(str);
    if (length > n) {
        return 0;
    }

    // Create a set to store distinct palindromic substrings
    char **set = (char **)malloc(n * sizeof(char *));
    int set_size = 0;

    for (int i = 0; i <= n - length; i++) {
        if (is_palindrome(str, i, length)) {
            // Extract the substring
            char *substr = (char *)malloc((length + 1) * sizeof(char));
            strncpy(substr, str + i, length);
            substr[length] = '\0';

            // Check if this substring is already in the set
            int exists = 0;
            for (int j = 0; j < set_size; j++) {
                if (strcmp(set[j], substr) == 0) {
                    exists = 1;
                    break;
                }
            }

            // If it's a new palindrome, add it to the set
            if (!exists) {
                set[set_size] = substr;
                set_size++;
            } else {
                free(substr);
            }
        }
    }

    // Free memory allocated for the set
    for (int i = 0; i < set_size; i++) {
        free(set[i]);
    }
    free(set);

    return set_size;
}

int main() {
    char str[100];
    int length;

    // Take input from the user
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter the length of substrings: ");
    scanf("%d", &length);

    int result = count_distinct_palindromic_substrings(str, length);
    printf("Number of distinct palindromic substrings of length %d: %d\n", length, result);

    return 0;
}
