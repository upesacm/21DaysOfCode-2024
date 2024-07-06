#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define MAX_DICT_SIZE 1000

bool canSegment(char *str, char **dict, int dictSize) {
    int strLen = strlen(str);
    bool dp[strLen + 1]; // dynamic programming array
    memset(dp, false, sizeof(dp));

    dp[0] = true; // empty string can be segmented

    for (int i = 1; i <= strLen; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && isValidWord(str + j, i - j, dict, dictSize)) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[strLen];
}

bool isValidWord(char *word, int wordLen, char **dict, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strlen(dict[i]) == wordLen && strncmp(word, dict[i], wordLen) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char *dict[] = {"apple", "pen", "applepen", "penapple", "pine", "pineapple"};
    int dictSize = sizeof(dict) / sizeof(dict[0]);

    char str[] = "pineapplepenapple";
    printf("%s\n", canSegment(str, dict, dictSize) ? "YES" : "NO");

    str[] = "catsandog";
    printf("%s\n", canSegment(str, dict, dictSize) ? "YES" : "NO");

    return 0;
}