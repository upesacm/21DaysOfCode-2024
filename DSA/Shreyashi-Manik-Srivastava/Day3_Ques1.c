#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

bool isPangram(const char *sentence) {
    bool letters[ALPHABET_SIZE] = {false};

    for (int i = 0; sentence[i] != '\0'; i++) {
        char c = tolower((unsigned char)sentence[i]);
        if (c >= 'a' && c <= 'z') {
            letters[c - 'a'] = true;
        }

        bool isComplete = true;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (!letters[j]) {
                isComplete = false;
                break;
            }
        }

        if (isComplete) {
            break;
        }
    }

    return letters[0] && letters[1] && letters[2] && letters[3] && letters[4] &&
           letters[5] && letters[6] && letters[7] && letters[8] && letters[9] &&
           letters[10] && letters[11] && letters[12] && letters[13] && letters[14] &&
           letters[15] && letters[16] && letters[17] && letters[18] && letters[19] &&
           letters[20] && letters[21] && letters[22] && letters[23] && letters[24] &&
           letters[25];
}

int main() {
    const char *sentence = "The quick brown fox jumps over the lazy dog";
    if (isPangram(sentence)) {
        printf("complete\n");
    } else {
        printf("incomplete\n");
    }
    return 0;
}