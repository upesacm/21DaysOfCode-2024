#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_COUNT 26
#define MAX_SENTENCE_LENGTH 1000

bool is_pangram(const char *sentence) {
    // Step 1: Initialize an array to keep track of letters
    bool letter_seen[ALPHABET_COUNT] = {false};

    // Step 2: Iterate through the sentence
    for (const char *ptr = sentence; *ptr != '\0'; ++ptr) {
        char ch = tolower(*ptr);
        if (ch >= 'a' && ch <= 'z') {
            letter_seen[ch - 'a'] = true;
        }
    }

    // Step 3: Check if all letters are seen
    for (int i = 0; i < ALPHABET_COUNT; ++i) {
        if (!letter_seen[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH];

    //input
    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) != NULL) {
        // Remove the newline character at the end, if any
        size_t len = strlen(sentence);
        if (len > 0 && sentence[len - 1] == '\n') {
            sentence[len - 1] = '\0';
        }

        //output
        if (is_pangram(sentence)) {
            printf("complete\n");
        } else {
            printf("incomplete\n");
        }
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
