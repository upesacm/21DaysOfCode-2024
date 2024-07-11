#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* check_pangram(char* sentence) {
    int alphabet[26] = {0}; 
    int i;

    for (i = 0; sentence[i]; i++) {
        char c = tolower(sentence[i]);
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a'] = 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            return "incomplete";
        }
    }

    return "complete";
}

int main() {
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strlen(sentence) - 1] = '\0'; 

    printf("%s\n", check_pangram(sentence));
    return 0;
}
