#include <stdio.h>

int main() {
    int threshold, n, i, onTimeArrivalsCount = 0;
    
    // Read the threshold number of students
    scanf("%d", &threshold);
    
    // Read the size of the arrival times array
    scanf("%d", &n);
    
    // Allocate memory for the arrival times array
    int* arrivalTimes = malloc(n * sizeof(int));
    if (arrivalTimes == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Read the arrival times
    for (i = 0; i < n; i++) {
        scanf("%d", &arrivalTimes[i]);
    }
    
    // Count the number of students who arrived on time
    for (i = 0; i < n; i++) {
        if (arrivalTimes[i] <= 0) { // Non-positive integer indicates on-time arrival
            onTimeArrivalsCount++;
        }
    }
    
    // Determine whether the class should be cancelled
    if (onTimeArrivalsCount < threshold) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    // Free allocated memory
    free(arrivalTimes);
    
    return 0;
}
