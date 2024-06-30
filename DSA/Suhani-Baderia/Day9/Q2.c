#include <stdio.h>
#include <stdbool.h>

bool isBalanced(char* str) {
    char stack[100];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1 || (str[i] == ')' && stack[top] != '(') || (str[i] == '}' && stack[top] != '{') || (str[i] == ']' && stack[top] != '[')) {
                return false;
            }
            top--;
        }
    }
    return top == -1;
}

int main() {
    char str[100];
    printf("Enter a string of brackets: ");
    scanf("%s", str);

    if (isBalanced(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
