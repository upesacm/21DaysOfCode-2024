#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int calculatemoves(int f, int newheight[]) {
    int moves = 0;
    int i = 0;
    while (i < f - 1) {
        if (newheight[i] > newheight[i + 1]) {
            moves++;
            i++;
            while (i < f - 1 && newheight[i] < newheight[i - 1]) {
                i++;
            }
        } else {
            i++;
        }
    }
    return moves;
}

int main() {
    int f;
    scanf("%d", &f);
    int newheight[f];
    for (int i = 0; i < f; i++) {
        scanf("%d", &newheight[i]);
    }
    printf("%d\n", calculatemoves(f, newheight));
    return 0;
}
