#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* checkASCIISymmetry(char* inputString) {
    int stringLength = strlen(inputString);
    
    for (int i = 0; i < stringLength / 2; i++) {
        if (abs(inputString[i] - inputString[i + 1]) != abs(inputString[stringLength - 1 - i] - inputString[stringLength - 2 - i])) {
            return "not symmetrical";
        }
    }
    
    return "symmetrical";
}

int main() {
    char inputString[100];
    
    printf("Enter a string: ");
    scanf("%s", inputString);
    
    printf("%s\n", checkASCIISymmetry(inputString));  
    
    return 0;
}
