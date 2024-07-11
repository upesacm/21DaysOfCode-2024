#include <stdio.h>
#include <stdlib.h>

const char* is_class_cancelled(int threshold, int arrival_times[], int n) {
    int on_time_count = 0;

    for (int i = 0; i < n; i++) {
        if (arrival_times[i] <= 0) {
            on_time_count++;
        }
    }

    if (on_time_count < threshold)
        return "YES";
    else
        return "NO";
}

int main() {
    int threshold, N;
    
    printf("Enter the minimum number of students to be present in class: ");
    scanf("%d", &threshold);

    printf("Enter the size of the arrival time array: ");
    scanf("%d", &N);

    // Dynamically allocate memory for the arrival_times array
    int *arrival_times = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        printf("Enter the %dth arrival time (positive indicates late & non-positive indicates on time): ", i+1);
        scanf("%d", &arrival_times[i]);
    }

    printf("%s\n", is_class_cancelled(threshold, arrival_times, N));

    // Free the allocated memory
    free(arrival_times);

    return 0;
}
