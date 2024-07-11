#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    bool dp[len + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && strchr(wordDict, s + j) != NULL) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[len];
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
