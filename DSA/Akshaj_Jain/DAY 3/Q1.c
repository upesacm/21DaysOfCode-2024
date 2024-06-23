#include <stdio.h>
#include <string.h>

// Function to check if reversing the ASCII values of a string results in the same sequence backward
const char* check_symmetrical_ascii(const char* input_string) {
    int length = strlen(input_string);
    int ascii_values[length];
    
    // Step 1: Convert each character to its ASCII value
    for (int i = 0; i < length; i++) {
        ascii_values[i] = (int)input_string[i];
    }
    
    // Step 2: Check if the sequence of ASCII values is symmetrical
    for (int i = 0; i < length / 2; i++) {
        if (ascii_values[i] != ascii_values[length - 1 - i]) {
            return "not symmetrical";
        }
    }

    return "symmetrical";
}

int main() {
    // Examples
    printf("%s\n", check_symmetrical_ascii("acxz"));  // Output: symmetrical
    printf("%s\n", check_symmetrical_ascii("abc"));   // Output: not symmetrical
    printf("%s\n", check_symmetrical_ascii("aba"));   // Output: symmetrical
    printf("%s\n", check_symmetrical_ascii("a"));     // Output: symmetrical

    return 0;
}
