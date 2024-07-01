#include <stdio.h>

int is_class_cancelled(int threshold, int arrival_times[], int size) {
    int on_time_count = 0;

    for (int i = 0; i < size; i++) {
        if (arrival_times[i] <= 0) {
            on_time_count++;
        }
    }

    if (on_time_count < threshold) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int threshold = 3;
    int arrival_times[] = {-1, -3, 4, 2};
    int size = sizeof(arrival_times) / sizeof(arrival_times[0]);

    int result = is_class_cancelled(threshold, arrival_times, size);
    if(result==1){
        printf("YES\n");
    } else{
        printf("NO\n");
    }

    return 0;
}
