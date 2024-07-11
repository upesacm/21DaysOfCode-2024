//Q1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInDictionary(const char* word, const char** dictionary, int dictionarySize) {
    for (int i = 0; i < dictionarySize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
const char* canSegmentString(const char* str, const char** dictionary, int dictionarySize) {
    int n = strlen(str);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // Empty string can always be segmented

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && isInDictionary(str + j, dictionary, dictionarySize)) {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n] ? "YES" : "NO";
}

int main() {
    const char* dictionary[] = {"apple", "pie"};
    int dictionarySize = sizeof(dictionary) / sizeof(dictionary[0]);
    const char* str = "applepie";

    printf("%s\n", canSegmentString(str, dictionary, dictionarySize)); // Output: YES

    return 0;
}


//Q2

#include <stdio.h>
#include <stdlib.h>

int getNumberOfDigits(int num) {
    if (num == 0) {
        return 1;
    }
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}
int isPalindromeHelper(int num, int* original, int numberOfDigits) {
    if (num == 0) {
        return 1;
    }

    if (!isPalindromeHelper(num / 10, original, numberOfDigits)) {
        return 0;
    }

    int divisor = (int)pow(10, numberOfDigits - 1);
    int leadingDigit = *original / divisor;
    int trailingDigit = num % 10;

    *original %= divisor;
    numberOfDigits -= 2;

    return leadingDigit == trailingDigit;
}
const char* isPalindrome(int num) {
    if (num < 0) {
        return "NO";
    }

    int original = num;
    int numberOfDigits = getNumberOfDigits(num);
    return isPalindromeHelper(num, &original, numberOfDigits) ? "YES" : "NO";
}

int main() {
    int number = 121;
    printf("%s\n", isPalindrome(number)); // Output: YES

    return 0;
}

