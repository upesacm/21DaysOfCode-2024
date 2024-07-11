#include <stdio.h>
int main() {
    int n; 
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int threshold; 
    printf("Enter the threshold number of students: ");
    scanf("%d", &threshold);
    int arrival_times[n];
    printf("Enter the arrival times of the students: ");
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
