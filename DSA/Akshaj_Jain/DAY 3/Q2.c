#include <stdio.h>
#include <string.h>

char* isSymmetricalASCII(char* str) {
    int len = strlen(str);
    
    for (int i = 0; i < len / 2; i++) {
        if ((int)str[i] != (int)str[len - 1 - i]) {
            return "not symmetrical";
        }
    }
    
    return "symmetrical";
}

int main() {
    char string1[] = "acxz";
    printf("%s\n", isSymmetricalASCII(string1));  
    
    return 0;
}
