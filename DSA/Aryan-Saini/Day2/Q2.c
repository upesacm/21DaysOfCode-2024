#include <stdio.h>
#include <stdlib.h>

int unique_leaderboard(int *scores, int size, int *unique_scores) {
    int unique_count = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || scores[i] != scores[i - 1]) {
            unique_scores[unique_count++] = scores[i];
        }
    }
    return unique_count;
}
void calculate_ranks(int *leaderboard, int leaderboard_size, int *player_scores, int player_size, int *ranks) {
    int *unique_scores = (int *)malloc(leaderboard_size * sizeof(int));
    int unique_leaderboard_size = unique_leaderboard(leaderboard, leaderboard_size, unique_scores);
    
    for (int i = 0; i < player_size; i++) {
        int player_score = player_scores[i];
        while (unique_leaderboard_size > 0 && player_score >= unique_scores[unique_leaderboard_size - 1]) {
            unique_leaderboard_size--;
        }
        ranks[i] = unique_leaderboard_size + 1;
    }
    
    free(unique_scores);
}

int main() {
    int leaderboard_size, player_size;
    printf("Enter the number of leaderboard scores: ");
    scanf("%d", &leaderboard_size);
    int *leaderboard = (int *)malloc(leaderboard_size * sizeof(int));
    printf("Enter the leaderboard scores in descending order:\n");
    for (int i = 0; i < leaderboard_size; i++) {
        scanf("%d", &leaderboard[i]);
    }
    printf("Enter the number of player's scores: ");
    scanf("%d", &player_size);
    int *player_scores = (int *)malloc(player_size * sizeof(int));
    printf("Enter the player's scores:\n");
    for (int i = 0; i < player_size; i++) {
        scanf("%d", &player_scores[i]);
    }
    int *ranks = (int *)malloc(player_size * sizeof(int));
    calculate_ranks(leaderboard, leaderboard_size, player_scores, player_size, ranks);
    printf("Player's ranks:\n");
    for (int i = 0; i < player_size; i++) {
        printf("%d ", ranks[i]);
    }
    printf("\n");
    free(leaderboard);
    free(player_scores);
    free(ranks);

    return 0;
}
