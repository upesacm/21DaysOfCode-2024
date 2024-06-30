#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHAR 256

// Function to check if the string can be rearranged to meet the criteria
const char* is_valid(const char *str) {
    int freq[MAX_CHAR] = {0};
    int len = strlen(str);

    // Count the frequency of each character in the string
    for (int i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    // Count the frequency of frequencies
    int freq_of_freq[MAX_CHAR] = {0};
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            freq_of_freq[freq[i]]++;
        }
    }

    // Count the number of different frequencies
    int diff_count = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq_of_freq[i] > 0) {
            diff_count++;
        }
    }

    // If all characters have the same frequency
    if (diff_count == 1) {
        return "valid";
    }

    // If there are two different frequencies, check if we can remove one character
    if (diff_count == 2) {
        int freq1 = 0, freq2 = 0;
        int count1 = 0, count2 = 0;

        for (int i = 0; i < MAX_CHAR; i++) {
            if (freq_of_freq[i] > 0) {
                if (freq1 == 0) {
                    freq1 = i;
                    count1 = freq_of_freq[i];
                } else {
                    freq2 = i;
                    count2 = freq_of_freq[i];
                }
            }
        }

        // Check if we can remove one character to make frequencies equal
        if ((count1 == 1 && (freq1 - 1 == freq2 || freq1 - 1 == 0)) ||
            (count2 == 1 && (freq2 - 1 == freq1 || freq2 - 1 == 0))) {
            return "valid";
        }
    }

    return "invalid";
}

int main() {
    char str[100];

    // Take input from the user
    printf("Enter a string: ");
    scanf("%s", str);

    const char* result = is_valid(str);
    printf("%s\n", result);

    return 0;
}
