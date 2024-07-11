#include <stdio.h>
#include <string.h>

char* is_symmetrical(const char* str) {
    int len = strlen(str);
    int i;

    for (i = 0; i < len / 2; i++) {
        if ((unsigned char)str[i]!= (unsigned char)str[len - i - 1]) {
            return "not symmetrical";
        }
    }

    return "symmetrical";
}

int main() {
    const char* str = "acxz";
    printf("String: %s\n", str);
    printf("Result: %s\n", is_symmetrical(str));

    str = "abcd";
    printf("String: %s\n", str);
    printf("Result: %s\n", is_symmetrical(str));

    return 0;
}
