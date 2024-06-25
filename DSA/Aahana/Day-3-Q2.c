#include <stdio.h>
#include <string.h>

char* check_symmetry(char* str) {
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if ((str[i] + str[len - i - 1])!= (str[0] + str[len - 1])) {
            return "not symmetrical";
        }
    }
    return "symmetrical";
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0'; 

    printf("%s\n", check_symmetry(str));
    return 0;
}
