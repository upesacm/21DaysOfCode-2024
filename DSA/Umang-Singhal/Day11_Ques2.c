#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void insert(int queue[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Priority Queue is full!\n");
        return;
    }
    queue[*size] = value;
    (*size)++;
    int i = *size - 1;
    while (i > 0 && queue[i] < queue[(i - 1) / 2]) {
        int temp = queue[i];
        queue[i] = queue[(i - 1) / 2];
        queue[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
int extract_min(int queue[], int *size) {
    if (*size <= 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    int min_value = queue[0];
    queue[0] = queue[*size - 1];
    (*size)--;
    int i = 0;
    while (i * 2 + 1 < *size) {
        int min_child = i * 2 + 1;
        if (i * 2 + 2 < *size && queue[i * 2 + 2] < queue[i * 2 + 1]) {
            min_child = i * 2 + 2;
        }
        if (queue[i] <= queue[min_child]) {
            break;
        }
        int temp = queue[i];
        queue[i] = queue[min_child];
        queue[min_child] = temp;
        i = min_child;
    }
    return min_value;
}
int main() {
    int queue[MAX_SIZE];
    int size = 0;
    int choice, value;
    while (1) {
        printf("1. Insert\n");
        printf("2. Extract Min\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(queue, &size, value);
                break;
            case 2:
                value = extract_min(queue, &size);
                if (value != -1) {
                    printf("Extracted Min: %d\n", value);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
