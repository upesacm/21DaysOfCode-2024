#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool canSegment(char* s, char** dict, int dictSize) {
    int n = strlen(s);
    bool dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = true; // empty string can be segmented

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                char temp[i - j + 1];
                strncpy(temp, s + j, i - j);
                temp[i - j] = '\0';
                for (int k = 0; k < dictSize; k++) {
                    if (strcmp(temp, dict[k]) == 0) {
                        dp[i] = true;
                        break;
                    }
                }
            }
            if (dp[i]) break;
        }
    }
    return dp[n];
}

int main() {
    char* str = "applepie";
    char* dict[] = {"apple", "pie"};
    int dictSize = sizeof(dict) / sizeof(dict[0]);

    if (canSegment(str, dict, dictSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
