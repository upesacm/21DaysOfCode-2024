#include<stdio.h>
#include<string.h>

void palindrome_(char s[100], int l) {
    int count = 0;
    for (int i = 0; i <= strlen(s) - l; i++) {
        char temp[l + 1];
        strncpy(temp, s + i, l);
        temp[l] = '\0';

        int is_palindrome = 1;
        for (int j = 0; j < l / 2; j++) {
            if (temp[j]!= temp[l - j - 1]) {
                is_palindrome = 0;
                break;
            }
        }

        if (is_palindrome) {
            count++;
        }
    }
    printf("Number of palindromic substrings of length %d: %d\n", l, count);
}

int main() {
    char s[100];
    int l;
    printf("Enter a string: ");
    scanf("%99s", s); 
    printf("Enter the length of substrings: ");
    scanf("%d", &l);
    palindrome_(s, l);  
    return 0;
}
