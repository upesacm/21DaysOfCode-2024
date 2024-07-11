#include <stdio.h>

int invertNumber(int n, int inverted) {
    if (n == 0) {
        return inverted;
    }
    inverted = inverted * 10 + n % 10;
    return invertNumber(n / 10, inverted);
}

int isNumberSymmetric(int n) {
    int invertedN = invertNumber(n, 0);
    return n == invertedN;
}

char* checkNumberSymmetry(int n) {
    if (isNumberSymmetric(n)) {
        return "The number is symmetric";
    } else {
        return "The number is not symmetric";
    }
}

int main() {
    int num = 121;
    printf("%s\n", checkNumberSymmetry(num));
    return 0;
}
