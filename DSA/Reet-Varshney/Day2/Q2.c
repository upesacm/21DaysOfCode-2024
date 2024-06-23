#include <stdio.h>

int calculate_rank(int score, int scores[], int scores_size) {
    int rank = 1;
    for (int i = 0; i < scores_size; i++) {
        if (score >= scores[i]) {
            return rank;
        }
        if (i == 0 || scores[i] != scores[i - 1]) {
            rank++;
        }
    }
    return rank;
}
void update_leaderboard(int scores[], int scores_size, int new_scores[], int new_scores_size, int ranks[]) {
    for (int i = 0; i < new_scores_size; i++) {
        ranks[i] = calculate_rank(new_scores[i], scores, scores_size);
    }
}

int main() {
    int leaderboard[] = {100, 90, 90, 80};
    int player_scores[] = {70, 80, 105};
    int leaderboard_size = sizeof(leaderboard) / sizeof(leaderboard[0]);
    int player_scores_size = sizeof(player_scores) / sizeof(player_scores[0]);
    int ranks[player_scores_size];
    update_leaderboard(leaderboard, leaderboard_size, player_scores, player_scores_size, ranks);
    printf("Player ranks after each new score:\n");
    for (int i = 0; i < player_scores_size; i++) {
        printf("Score: %d - Rank: %d\n", player_scores[i], ranks[i]);
    }
    return 0;
}

