#include <stdio.h>
#include <string.h>
#include <limits.h>

int findMinCost(char* str) {
    int n = strlen(str);
    int total_x = 0, total_y = 0;
    int left_x = 0, left_y = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'x') total_x++;
        else total_y++;
    }
    int min_cost = INT_MAX;
    for (int i = 0; i <= n; i++) {
        int remaining_x = total_x - left_x;
        int removed_y = left_y;

        int current_cost = remaining_x > removed_y ? remaining_x : removed_y;
        if (current_cost < min_cost) {
            min_cost = current_cost;
        }

      
        if (i < n) {
            if (str[i] == 'x') left_x++;
            else left_y++;
        }
    }

    return min_cost;
}

int main() {
    char str[100005];
    printf("Enter the string: ");
    scanf("%s", str);

    int result = findMinCost(str);
    printf("%d\n", result);

    return 0;
}
