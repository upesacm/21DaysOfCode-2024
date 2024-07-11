#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* is_pangram(const char* sentence) {
    int alphabet[26] = {0};  
    int i;

    for (i = 0; sentence[i]!= '\0'; i++) {
        char c = tolower((unsigned char)sentence[i]); 
        if (c >= 'a' && c <= 'z') {
            alphabet[c - 'a'] = 1;         }
    }

    for (i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            return "incomplete";
        }
    }

    return "complete";
}

int main() {
    const char* sentence = "The quick brown fox jumps over the lazy dog";
    printf("Sentence: %s\n", sentence);
    printf("Result: %s\n", is_pangram(sentence));

    sentence = "Hello World";
    printf("Sentence: %s\n", sentence);
    printf("Result: %s\n", is_pangram(sentence));

    return 0;
}
