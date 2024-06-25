#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

char* can_be_rearranged(char* str) {
    int freq[256] = {0}; // assuming ASCII characters
    for (int i = 0; str[i]; i++) {
        freq[(int)str[i]]++;
    }

    int unique_freq[256] = {0};
    int unique_freq_count = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            unique_freq[unique_freq_count++] = freq[i];
        }
    }

    qsort(unique_freq, unique_freq_count, sizeof(int), compare);

    if (unique_freq_count == 1) {
        return "valid";
    } else if (unique_freq_count > 2) {
        return "invalid";
    } else {
        if (unique_freq[1] - unique_freq[0] == 1 && unique_freq[1] == unique_freq_count - 1) {
            return "valid";
        } else {
            return "invalid";
        }
    }
}

int main() {
    char str[] = "aabbcc";
    char* result = can_be_rearranged(str);
    printf("%s\n", result);
    return 0;
}
