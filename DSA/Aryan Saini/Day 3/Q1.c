#include <stdio.h>
#include <ctype.h>


const char* is_pangram(const char* sentence) {
    int letters[26] = {0}; 
    int index;
    

    for (int i = 0; sentence[i] != '\0'; i++) {

        if (isalpha(sentence[i])) {

            index = tolower(sentence[i]) - 'a';

            letters[index] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            return "incomplete";
        }
    }
    
    return "complete";
}

int main() {
    char sentence[1000];
    

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    

    printf("%s\n", is_pangram(sentence));
    
    return 0;
}
