#include <stdio.h>
#include <ctype.h>
int main() {
    char sentence[1000];
    int alphabet[26] = {0}; 
    int i = 0;
    int isComplete = 1;
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    while (sentence[i] != '\0') {
        if (isalpha(sentence[i])) {
            alphabet[tolower(sentence[i]) - 'a'] = 1;
        }
        i++;
    }
    for (i = 0; i < 26; i++) {
        if (alphabet[i] == 0) {
            isComplete = 0;
            break;
        }
    }
    if (isComplete) {
        printf("complete\n");
    } else {
        printf("incomplete\n");
    }
    return 0;
}
