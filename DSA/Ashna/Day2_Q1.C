#include <stdio.h>

int main() {
    int threshold, n;
    printf("Enter the threshold number of students: ");
    scanf("%d", &threshold); 

    printf("Enter the number of students: ");
    scanf("%d", &n); 

    int arrival_times[n];
    printf("Enter the arrival times of %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for student %d: ", i + 1);
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
