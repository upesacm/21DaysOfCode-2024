#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* sym_checker(char str[]) {
    int size = strlen(str);
    int stack[size];
    char queue[size];
    int front = 0, rear = 0;
    int top = -1;

    for (int i = 0; i < size; i++) {
        if (isalpha(str[i])) {
            queue[rear++] = str[i];
            if (isupper(str[i])) {
                stack[++top] = 'Z' - (str[i] - 'A');
            } else if (islower(str[i])) {
                stack[++top] = 'z' - (str[i] - 'a');
            }
        }
    }

    int count = 0;
    for (int i = 0; i < rear; i++) {
        if (stack[top--] == queue[i]) {
            count++;
        }
    }

    if (count == rear) {
        return "Symmetrical";
    } else {
        return "Not Symmetrical";
    }
}

int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    const char* ans = sym_checker(str);
    printf("%s\n", ans);
    return 0;
}
