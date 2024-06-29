#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char str[100005];
    scanf("%s", str);

    int n = strlen(str);
    int x_count = 0, y_count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'x') x_count++;
        else y_count++;
    }

    int res = x_count;
    int x_left = 0, y_removed = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'x') x_left++;
        else y_removed++;
        res = fmin(res, fmax(x_left, y_removed));
    }

    printf("%d\n", res);
    return 0;
}
