#include <stdio.h>
#include <stdlib.h>

int min_moves_to_sort(int n, int heights[]) {
    int moves = 0;
    int *new_heights = (int *)malloc(n * sizeof(int));
    while (1) {
        int new_size = 0;
        int sorted = 1;
        for (int i = 1; i < n; i++) {
            if (heights[i] < heights[i - 1]) {
                sorted = 0;
                break;
            }
        }
        if (sorted) break;
        new_heights[0] = heights[0];
        new_size = 1;
        for (int i = 1; i < n; i++) {
            if (heights[i] >= heights[i - 1]) {
                new_heights[new_size] = heights[i];
                new_size++;
            }
        }
        for (int i = 0; i < new_size; i++) {
            heights[i] = new_heights[i];
        }
        n = new_size;
        moves++;
    }
    free(new_heights);
    return moves;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    int *heights = (int *)malloc(n * sizeof(int));
    printf("Enter the heights of the students: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }
    int result = min_moves_to_sort(n, heights);
    printf("Minimum number of moves: %d\n", result);

    free(heights);
    return 0;
}
