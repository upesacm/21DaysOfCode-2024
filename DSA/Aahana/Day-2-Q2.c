#include <stdio.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void climbingLeaderboard(int leaderboard[], int leaderboard_size, int player_scores[], int player_scores_size, int result[]) {
    sort(leaderboard, leaderboard_size);
    int j = 0;
    for (int i = 0; i < player_scores_size; i++) {
        while (j < leaderboard_size && player_scores[i] >= leaderboard[j]) {
            j++;
        }
        result[i] = j + 1;
    }
}

int main() {
    int leaderboard[] = {100, 90, 90, 80};
    int player_scores[] = {70, 80, 105};
    int leaderboard_size = sizeof(leaderboard) / sizeof(leaderboard[0]);
    int player_scores_size = sizeof(player_scores) / sizeof(player_scores[0]);
    int result[player_scores_size];
    climbingLeaderboard(leaderboard, leaderboard_size, player_scores, player_scores_size, result);
    for (int i = 0; i < player_scores_size; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
