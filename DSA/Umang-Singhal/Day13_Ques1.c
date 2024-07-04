#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isInDictionary(const char* word, const char* dictionary[], int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}
bool canBeSegmented(const char* str, const char* dictionary[], int dictSize) {
    int len = strlen(str);
    bool dp[len + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            char word[i - j + 1];
            strncpy(word, str + j, i - j);
            word[i - j] = '\0';

            if (dp[j] && isInDictionary(word, dictionary, dictSize)) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}

int main() {
    const char* dictionary[] = {"apple", "pie"};
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
    const char* str = "applepie";

    if (canBeSegmented(str, dictionary, dictSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
