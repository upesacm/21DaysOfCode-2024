#include <stdio.h>
#include <string.h>
#define ALPHABET_SIZE 26

const char* is_valid_string(char* str) {
    int char_count[ALPHABET_SIZE] = {0};
    int fre_count[ALPHABET_SIZE + 1] = {0};
    int len = strlen(str);
 
    for (int i = 0; i < len; i++) {
        char_count[str[i] - 'a']++;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (char_count[i] > 0) {
            fre_count[char_count[i]]++;
        }
    }
    
    int fre = 0;
    int f1 = 0, f2 = 0;

    for (int i = 1; i <= len; i++) {
        if (fre_count[i] > 0) {
            fre++;
            if (f1== 0) {
                f1= i;
            } else {
                f2 = i;
            }
        }
    }
    if (fre == 1) {
        return "valid"; 
    }
    if (fre == 2) {
        if ((fre_count[f1
] == 1 && f1
 - 1 == f2) ||
            (fre_count[f2] == 1 && f2 - 1 == f1
    )) {
            return "valid";
        }
        if (fre_count[1] == 1) {
            return "valid";
        }
    }
    
    return "invalid";
}

int main() 
{
    char str[] = "aabbcc";
    printf("Output: %s\n", is_valid_string(str));
    return 0;
}
