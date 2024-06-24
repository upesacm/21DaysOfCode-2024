#include <stdio.h>
const char* check_class_cancellation(int student_threshold, int student_arrivals[], int num_students) {
    int on_time_count = 0;
    for (int i = 0; i < num_students; i++) {
        if (student_arrivals[i] <= 0) {
            on_time_count++;
        }
    }
    if (on_time_count < student_threshold) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    int student_threshold;
    int num_students;
    printf("Enter the threshold number of students: ");
    scanf("%d", &student_threshold);
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    int student_arrivals[num_students];
    printf("Enter the arrival times of the students:\n");
    for (int i = 0; i < num_students; i++) {
        scanf("%d", &student_arrivals[i]);
    }

    const char* result = check_class_cancellation(student_threshold, student_arrivals, num_students);
    printf("%s\n", result);

    return 0;
}
