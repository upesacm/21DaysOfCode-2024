#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100
#define MAX_WORDS 100

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    bool dp[MAX_LENGTH + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    for (int i = 1; i <= strlen(s); i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && strchr(wordDict, s + j) != NULL) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[strlen(s)];
}

int main() {
    char* s = "applepie";
    char* wordDict[] = {"apple", "pie"};
    int wordDictSize = sizeof(wordDict) / sizeof(wordDict[0]);

    if (wordBreak(s, wordDict, wordDictSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
