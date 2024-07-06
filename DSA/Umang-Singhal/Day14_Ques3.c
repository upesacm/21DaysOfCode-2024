#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int hallway[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &hallway[i]);
    }
    int bulbs_on = 0;
    int furthest_lit = -1;
    for (int i = 0; i < n;) {
        if (hallway[i] == -1) {
            i++;
            continue; 
        }
        int max_reach = i + hallway[i];
        if (max_reach >= n - 1) {
            bulbs_on++;
            break; 
        }
        int next_position = -1;
        for (int j = i + 1; j <= max_reach; ++j) {
            if (hallway[j] != -1) {
                next_position = j;
            }
        }
        if (next_position == -1) {
            bulbs_on = -1;
            break;
        }
        bulbs_on++;
        furthest_lit = next_position + hallway[next_position];
        i = next_position + 1;
    }
    if (furthest_lit < n - 1) {
        bulbs_on = -1;
    }
    printf("%d\n", bulbs_on);
    
    return 0;
}
