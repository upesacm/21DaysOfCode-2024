#include <stdio.h>
#include <string.h>
#define MAX_CHAR 26

const char* is_valid(char* str) {
    int char_freq[MAX_CHAR] = {0};
    int freq_count[MAX_CHAR] = {0};
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char_freq[str[i]]++;
    }
    for (int i = 0; i < MAX_CHAR; i++) {
        if (char_freq[i] > 0) {
            freq_count[char_freq[i]]++;
        }
    }
    int freq1 = 0, count1 = 0, freq2 = 0, count2 = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq_count[i] > 0) {
            if (freq1 == 0) {
                freq1 = i;
                count1 = freq_count[i];
            } else if (freq2 == 0) {
                freq2 = i;
                count2 = freq_count[i];
            } else {
                return "invalid";
            }
        }
    }
    if (freq2 == 0) {
        return "valid";
    }
    if ((count1 == 1 && (freq1 - 1 == freq2 || freq1 == 1)) ||
        (count2 == 1 && (freq2 - 1 == freq1 || freq2 == 1))) {
        return "valid";
    }
    return "invalid";
}

int main() {
    char str[] = "aabbbccc";
    const char* result = is_valid(str);
    printf("Output: %s\n", result);
    return 0;
}
