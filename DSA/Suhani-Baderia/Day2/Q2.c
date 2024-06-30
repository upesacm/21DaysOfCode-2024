#include <stdio.h>

int find_rank(int player_score, int leaderboard[], int leaderboard_size) {
    int rank = 1;
    for (int i = 0; i < leaderboard_size; i++) {
        if (player_score >= leaderboard[i]) {
            return rank;
        }
        if (i == 0 || leaderboard[i] != leaderboard[i - 1]) {
            rank++;
        }
    }
    return rank;
}

void climbing_leaderboard(int leaderboard[], int leaderboard_size, int player_scores[], int player_scores_size, int ranks[]) {
    for (int i = 0; i < player_scores_size; i++) {
        ranks[i] = find_rank(player_scores[i], leaderboard, leaderboard_size);
    }
}

int main() {
    int leaderboard[] = {100, 90, 90, 80};
    int player_scores[] = {70,80,105};
    int leaderboard_size = sizeof(leaderboard) / sizeof(leaderboard[0]);
    int player_scores_size = sizeof(player_scores) / sizeof(player_scores[0]);
    int ranks[player_scores_size];

    climbing_leaderboard(leaderboard, leaderboard_size, player_scores, player_scores_size, ranks);

    printf("Player's ranks after each score:\n");
    for (int i = 0; i < player_scores_size; i++) {
        printf("%d ", ranks[i]);
    }
    printf("\n");

    return 0;
}
