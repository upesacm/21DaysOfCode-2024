#include <stdio.h>
#include <string.h>
const char* checkSymmetry(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return "not symmetrical";
        }
    }
    return "symmetrical";
}
int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    const char* result = checkSymmetry(str);
    printf("%s\n", result);
    return 0;
}
