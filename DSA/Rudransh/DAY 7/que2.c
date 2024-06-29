#include <stdio.h>
#include <string.h>
#include <limits.h>

int min_max_x_y_operations(char* str) {
    int n = strlen(str);
    int total_x = 0, total_y = 0;
    
    for (int i = 0; i < n; i++) {
        if (str[i] == 'x') {
            total_x++;
        } else {
            total_y++;
        }
    }
    
    int y_removed_begin = 0;
    int x_remaining = total_x;
    int min_value = INT_MAX;
    
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            if (str[i - 1] == 'y') {
                y_removed_begin++;
            } else {
                x_remaining--;
            }
        }
        
        int current_max = x_remaining > y_removed_begin ? x_remaining : y_removed_begin;
        if (current_max < min_value) {
            min_value = current_max;
        }
    }
    
    return min_value;
}

int main() {
    char str[100005];
    scanf("%s", str);
    
    int result = min_max_x_y_operations(str);
    printf("%d", result);
    
    return 0;
}
