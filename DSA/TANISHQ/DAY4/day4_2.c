#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* canRearrangeValid(char* str) {
    int freq[256] = {0}; // Array to store frequency of each character
    int oddCount = 0; // Counter for odd frequency

    // Count frequency of each character
    for (int i = 0; i < strlen(str); i++) {
        freq[tolower(str[i])]++; // Convert to lowercase and increment frequency
    }

    // Check for odd frequency
    for (int i = 0; i < 256; i++) {
        if (freq[i] % 2!= 0) {
            oddCount++;
            if (oddCount > 1) break; // More than one character has odd frequency
        }
    }

    // If all frequencies are even or exactly one frequency is odd, return "valid"
    if (oddCount <= 1) {
        return "valid";
    } else {
        return "invalid";
    }
}

int main() {
    char str[] = "aabbcc";
    printf("%s\n", canRearrangeValid(str));

    return 0;
}
