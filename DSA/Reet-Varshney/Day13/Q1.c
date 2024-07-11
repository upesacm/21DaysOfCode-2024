#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canBeSegmented(char* str, char** dict, int dictSize) {
    int len = strlen(str);
    bool segmented[len + 1];
    memset(segmented, false, sizeof(segmented));
    segmented[0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (segmented[j] && isValidWord(str + j, i - j, dict, dictSize)) {
                segmented[i] = true;
                break;
            }
        }
    }

    return segmented[len];
}

bool isValidWord(char* word, int wordLen, char** dict, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strlen(dict[i]) == wordLen && strncmp(word, dict[i], wordLen) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char* inputStr = "applepie";
    char* wordDictionary[] = {"apple", "pie"};
    int dictSize = sizeof(wordDictionary) / sizeof(wordDictionary[0]);

    if (canBeSegmented(inputStr, wordDictionary, dictSize)) {
        printf("The string can be segmented into dictionary words.\n");
    } else {
        printf("The string cannot be segmented into dictionary words.\n");
    }

    return 0;
