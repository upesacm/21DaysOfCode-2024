#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    int* dp = (int*)malloc((len + 1) * sizeof(int));
    dp[0] = 1;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j]) {
                char* sub = (char*)malloc((i - j + 1) * sizeof(char));
                strncpy(sub, s + j, i - j);
                sub[i - j] = '\0';
                for (int k = 0; k < wordDictSize; k++) {
                    if (strcmp(sub, wordDict[k]) == 0) {
                        dp[i] = 1;
                        break;
                    }
                }
                free(sub);
                if (dp[i]) break;
            }
        }
    }

    int result = dp[len];
    free(dp);
    return result;
}

int main() {
    char string[100];
    int dictSize;

    printf("Enter the string: ");
    scanf("%s", string);

    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &dictSize);

    char** dictionary = (char**)malloc(dictSize * sizeof(char*));
    for (int i = 0; i < dictSize; i++) {
        dictionary[i] = (char*)malloc(100 * sizeof(char));
        printf("Enter word %d: ", i + 1);
        scanf("%s", dictionary[i]);
    }

    if (wordBreak(string, dictionary, dictSize)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    for (int i = 0; i < dictSize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    return 0;
}
