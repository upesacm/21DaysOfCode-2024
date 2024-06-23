#include <stdio.h>

int main() {
    int threshold, n;
    scanf("%d %d", &threshold, &n);

    int arrival_times[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival_times[i]);
    }

    int on_time_count = 0;
    for (int i = 0; i < n; i++) {
        if (arrival_times[i] <= 0) {
            on_time_count++;
        }
    }

    if (on_time_count < threshold) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
