#include <stdio.h>
#include <string.h>

const char* is_valid(const char* str) {
    int freq[26] = {0};
    int i, max_freq = 0, min_freq = 26, max_count = 0, min_count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            if (freq[i] > max_freq) {
                max_freq = freq[i];
            }
            if (freq[i] < min_freq) {
                min_freq = freq[i];
            }
        }
    }

    for (i = 0; i < 26; i++) {
        if (freq[i] == max_freq) {
            max_count++;
        }
        if (freq[i] == min_freq) {
            min_count++;
        }
    }

    if (max_freq == min_freq) {
        return "valid";
    } else if (max_count == 1 && (max_freq - 1 == min_freq || max_freq == 1)) {
        return "valid";
    } else if (min_count == 1 && min_freq == 1) {
        return "valid";
    } else {
        return "invalid";
    }
}

int main() {
    const char* string = "aabbcc";
    printf("Output: %s\n", is_valid(string));
    return 0;
}
