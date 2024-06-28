#include <stdio.h>

int maxCommonHeight(int stackA[], int stackB[], int stackC[], int lenA, int lenB, int lenC) {
    int heightA = 0, heightB = 0, heightC = 0;
    for (int i = 0; i < lenA; i++) heightA += stackA[i];
    for (int i = 0; i < lenB; i++) heightB += stackB[i];
    for (int i = 0; i < lenC; i++) heightC += stackC[i];

    int idxA = 0, idxB = 0, idxC = 0;

    while (true) {
        if (heightA == heightB && heightB == heightC) return heightA;
        if (heightA >= heightB && heightA >= heightC) heightA -= stackA[idxA++];
        else if (heightB >= heightA && heightB >= heightC) heightB -= stackB[idxB++];
        else if (heightC >= heightA && heightC >= heightB) heightC -= stackC[idxC++];
    }
}

int main() {
    int stackA[] = {3, 2, 1, 1, 1};
    int stackB[] = {4, 3, 2};
    int stackC[] = {1, 1, 4, 1};
    int lenA = sizeof(stackA) / sizeof(stackA[0]);
    int lenB = sizeof(stackB) / sizeof(stackB[0]);
    int lenC = sizeof(stackC) / sizeof(stackC[0]);
    printf("%d\n", maxCommonHeight(stackA, stackB, stackC, lenA, lenB, lenC));
    return 0;
}
