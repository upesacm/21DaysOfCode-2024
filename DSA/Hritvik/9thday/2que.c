#include <stdio.h>
#include <stdbool.h>

bool isBalanced(char* str) {
    char stack[100];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        } else if (ch == ')' && (top == -1 || stack[top--] != '(')) {
            return false;
        } else if (ch == '}' && (top == -1 || stack[top--] != '{')) {
            return false;
        } else if (ch == ']' && (top == -1 || stack[top--] != '[')) {
            return false;
        }
    }
    return top == -1;
}

int main() {
    char str[100];
    printf("Enter a sequence of brackets: ");
    scanf("%s", str);

    printf(isBalanced(str) ? "Balanced\n" : "Not Balanced\n");

    return 0;
}
