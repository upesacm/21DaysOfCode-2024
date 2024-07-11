#include <stdio.h>
#include <string.h>

int main() {
    char str[100005];
    scanf("%s", str);

    int len = strlen(str);
    int total_x = 0, total_y = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == 'x') {
            total_x++;
        } else {
            total_y++;
        }
    }

    int min_cost = len;

    int left_x = 0, left_y = 0;
    for (int i = 0; i <= len; i++) {
        int right_x = total_x - left_x;
        int removed_y = left_y;

        int cost = (right_x > removed_y) ? right_x : removed_y;
        if (cost < min_cost) {
            min_cost = cost;
        }

        if (i < len) {
            if (str[i] == 'x') {
                left_x++;
            } else {
                left_y++;
            }
        }
    }

    int right_x = 0, right_y = 0;
    for (int i = len - 1; i >= 0; i--) {
        int left_x = total_x - right_x;
        int removed_y = right_y;

        int cost = (left_x > removed_y) ? left_x : removed_y;
        if (cost < min_cost) {
            min_cost = cost;
        }

        if (i >= 0) {
            if (str[i] == 'x') {
                right_x++;
            } else {
                right_y++;
            }
        }
    }

    printf("%d\n", min_cost);

    return 0;
}
