// Question 2: Determine if a string can be rearranged such that all characters have the same frequency. 
//If one removal can achieve this, return "valid", otherwise return "invalid".

// Inputs:
// A string.
// Output:
// "valid" if the string meets the criteria, otherwise "invalid"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of each character in the string
void countFrequencies(const char *s, int *freq) {
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }
}

// Function to determine if the string is valid according to the criteria
const char* isValidString(const char *s) {
    int freq[26] = {0};
    countFrequencies(s, freq);

    int freqCount[100] = {0};
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freqCount[freq[i]]++;
        }
    }

    int uniqueFreqCount = 0;
    int uniqueFreq1 = 0, uniqueFreq2 = 0;
    for (int i = 0; i < 100; i++) {
        if (freqCount[i] > 0) {
            uniqueFreqCount++;
            if (uniqueFreq1 == 0) {
                uniqueFreq1 = i;
            } else {
                uniqueFreq2 = i;
            }
        }
    }

    if (uniqueFreqCount == 1) {
        return "valid";
    } else if (uniqueFreqCount == 2) {
        if ((freqCount[uniqueFreq1] == 1 && (uniqueFreq1 - 1 == uniqueFreq2 || uniqueFreq1 - 1 == 0)) ||
            (freqCount[uniqueFreq2] == 1 && (uniqueFreq2 - 1 == uniqueFreq1 || uniqueFreq2 - 1 == 0))) {
            return "valid";
        }
    }

    return "invalid";
}

int main() {
    char s[] = "aabbcc";
    printf("%s\n", isValidString(s)); // Output: valid

    char t[] = "aabbccc";
    printf("%s\n", isValidString(t)); // Output: valid

    char u[] = "aabbcccc";
    printf("%s\n", isValidString(u)); // Output: invalid

    return 0;
}

