#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isInDictionary(const char *word, const char **dictionary, int dictSize) {
    for (int i = 0; i < dictSize; ++i) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}


int canSegmentString(const char *string, const char **dictionary, int dictSize) {
    int n = strlen(string);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; 

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            char subStr[i - j + 1];
            strncpy(subStr, string + j, i - j);
            subStr[i - j] = '\0';
            if (dp[j] && isInDictionary(subStr, dictionary, dictSize)) {
                dp[i] = 1;
                break;
            }
        }
    }

    return dp[n];
}

int main() {
    char string[100];
    int dictSize;
    printf("Enter the string: ");
    scanf("%s", string);

    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &dictSize);

    const char **dictionary = (const char **)malloc(dictSize * sizeof(char *));
    for (int i = 0; i < dictSize; ++i) {
        dictionary[i] = (char *)malloc(50 * sizeof(char));
        printf("Enter word %d: ", i + 1);
        scanf("%s", (char *)dictionary[i]);
    }

    if (canSegmentString(string, dictionary, dictSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    for (int i = 0; i < dictSize; ++i) {
        free((char *)dictionary[i]);
    }
    free(dictionary);

    return 0;
}
