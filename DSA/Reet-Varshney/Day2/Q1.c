#include <stdio.h>

int checkClassCancellation(int minRequired, int arrivalTimes[], int numStudents) {
    int onTimeCount = 0;
    for (int i = 0; i < numStudents; i++) {
        if (arrivalTimes[i] <= 0) {
            onTimeCount++;
        }
    }
    if (onTimeCount < minRequired) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int minRequired = 3;
    int arrivalTimes[] = {-1, -3, 4, 2};
    int numStudents = sizeof(arrivalTimes) / sizeof(arrivalTimes[0]);
    int isCancelled = checkClassCancellation(minRequired, arrivalTimes, numStudents);
    if (isCancelled == 1) {
        printf("Class is cancelled\n");
    } else {
        printf("Class is not cancelled\n");
    }
    return 0;
}

