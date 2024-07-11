#include <stdio.h>
#include <string.h>

int is_palindrome(char str[], int start, int len) {
    int end = start + len - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

int palindrome(char str[], int len) {
    int size = strlen(str);
    char substrings[size - len + 1][len + 1];
    int count = 0;

    for (int i = 0; i <= size - len; i++) {
        if (is_palindrome(str, i, len)) {
            // Extract the substring
            strncpy(substrings[count], str + i, len);
            substrings[count][len] = '\0'; // Null-terminate the substring
            count++;
        }
    }

    int f_count = 0;
    for (int i = 0; i < count; i++) {
        int is_unique = 1;
        for (int j = 0; j < i; j++) {
            if (strcmp(substrings[i], substrings[j]) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            f_count++;
        }
    }

    return f_count;
}

int main() {
    char str[100];
    int len;
    
    printf("Enter the sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    
    printf("Enter the length of substring: ");
    scanf("%d", &len);
    
    int ans = palindrome(str, len);
    printf("%d", ans);
    
    return 0;
}
