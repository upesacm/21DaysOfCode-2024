#include <stdio.h>
#include <string.h>

char* checkPangram(char* input) {
    int letterTracker[26] = {0};
    int charIndex;
    for (int i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        
        if (currentChar >= 'A' && currentChar <= 'Z') {
            currentChar = currentChar + ('a' - 'A');
        }
        if (currentChar >= 'a' && currentChar <= 'z') {
            charIndex = currentChar - 'a';
            letterTracker[charIndex] = 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (letterTracker[i] == 0) {
            return "This sentence is not a pangram.";
        }
    }
    return "This sentence is a pangram.";
}

int main() {
    char sampleSentence[] = "The quick brown fox jumps over the lazy dog";
    printf("%s\n", checkPangram(sampleSentence)); 
    return 0;
}
