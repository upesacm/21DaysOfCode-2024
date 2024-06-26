#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

char* checkSymmetry(char* input) {
    int len = strlen(input);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    char* swapped = (char*)malloc((len + 1) * sizeof(char));

    // Convert input to lowercase
    for (int i = 0; i < len; i++) {
        input[i] = tolower((unsigned char)input[i]);
    }

    // Reverse the input string
    for (int i = 0; i < len; i++) {
        reversed[i] = input[len - i - 1];
    }
    reversed[len] = '\0'; // Null-terminate the reversed string

    // Swap the characters in the reversed string
    for (int i = 0; i < len; i++) {
        swapped[i] = 'z' - (reversed[i] - 'a');
    }
    swapped[len] = '\0'; // Null-terminate the swapped string

    // Check if the input string is symmetrical
    if (strcmp(input, swapped) == 0) {
        return "symmetrical";
    } else {
        return "not symmetrical";
    }
}

int main() {
    char input[256];
    printf("Enter a string: ");
    fgets(input, 256, stdin);

    // Remove the newline character from the input string
    input[strcspn(input, "\n")] = 0;

    printf("%s\n", checkSymmetry(input));
    return 0;
}