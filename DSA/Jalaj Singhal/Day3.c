#include <stdio.h>
#include <ctype.h>
const char* check(const char* sen) {
    int alphabet[26] = {0};
    for (const char* p = sen; *p != '\0'; ++p) {
        char c = tolower(*p); 
        if ('a' <= c && c <= 'z') {
            alphabet[c - 'a'] = 1;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (alphabet[i] == 0) {
            return "incomplete"; 
        }
    }
    return "complete"; 
}
int main() {
    char sen[1000]; 
    printf("Enter sentence: ");
    for(int i = 0; i < 1000; i++ ) {
        scanf("%d", &sen[i]);
    }
    const char *result = check(sen);
    printf("Result: %s\n", result);
    return 0;
}
