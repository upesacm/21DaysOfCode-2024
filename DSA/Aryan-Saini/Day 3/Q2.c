#include <stdio.h>
#include <string.h>

const char* is_symmetrical(const char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return "not symmetrical";
        }
    }
    
    return "symmetrical";
}
int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    

    str[strcspn(str, "\n")] = '\0';
    
    printf("%s\n", is_symmetrical(str));
    
    return 0;
}
