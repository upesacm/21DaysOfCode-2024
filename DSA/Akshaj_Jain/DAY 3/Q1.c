#include <stdio.h>
#include <string.h>

char* isPangram(char* sentence) {
    int alphabet[26] = {0};
    int index;
    
    for (int i = 0; i < strlen(sentence); i++) {
        char ch = sentence[i];
        
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A');
        }
        
        if (ch >= 'a' && ch <= 'z') {
            index = ch - 'a';
            alphabet[index] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            return "incomplete";
        }
    }
    
    return "complete";
}

int main() {
    char sentence1[] = "The quick brown fox jumps over the lazy dog";
    printf("%s\n", isPangram(sentence1));  
    
    
    return 0;
}
