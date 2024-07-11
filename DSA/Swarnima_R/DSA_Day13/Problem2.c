#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalinRec(char* numStr, int left, int right) {
    if (left >= right) return true;
    if (numStr[left] != numStr[right]) return false;
    return isPalinRec(numStr, left + 1, right - 1);
}

bool isPalin(int num) {
    char numStr[20];
    sprintf(numStr, "%d", num);
    return isPalinRec(numStr, 0, strlen(numStr) - 1);
}

int main() {
    int num = 121;
    if (isPalin(num)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
