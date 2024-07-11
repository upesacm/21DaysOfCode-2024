#include <stdio.h>
#include <string.h>
int isPalindrome(char *str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}
int main() {
    char str[100];
    int len, i, j, k, substr_length;
    int count = 0;
    printf("Enter the string: ");
    scanf("%s", str);
    printf("Enter the length of substrings: ");
    scanf("%d", &substr_length);
    len = strlen(str);
    char palindromes[100][100];
    int palindrome_count = 0;
    for (i = 0; i <= len - substr_length; i++) {
        int is_distinct = 1;
        if (isPalindrome(str, i, i + substr_length - 1)) {
            char temp[100];
            for (j = 0; j < substr_length; j++) {
                temp[j] = str[i + j];
            }
            temp[j] = '\0';
            for (k = 0; k < palindrome_count; k++) {
                if (strcmp(palindromes[k], temp) == 0) {
                    is_distinct = 0;
                    break;
                }
            }
            if (is_distinct) {
                strcpy(palindromes[palindrome_count], temp);
                palindrome_count++;
                count++;
            }
        }
    }
    printf("The number of distinct palindromic substrings of length %d is: %d\n", substr_length, count);
    return 0;
}
