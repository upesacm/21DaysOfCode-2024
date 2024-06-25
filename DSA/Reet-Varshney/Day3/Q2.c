#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* isSymmetrical(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (abs(str[i] - str[i + 1]) != abs(str[len - 1 - i] - str[len - 2 - i])) {
            return "not symmetrical";
        }
    }
    return "symmetrical";
}

int main() {
    char userInput[100];
    printf("Enter a string: ");
    scanf("%s", userInput);
    printf("%s\n", isSymmetrical(userInput));  
    return 0;
}
