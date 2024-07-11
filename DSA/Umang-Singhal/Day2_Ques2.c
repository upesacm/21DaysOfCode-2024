#include <stdio.h>
int main() {
    int n, m; 
    printf("Enter the number of leaderboard scores: ");
    scanf("%d", &n);
    int leaderboard[n]; 
    printf("Enter the leaderboard scores: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &leaderboard[i]);
    }
    printf("Enter the number of player's scores: ");
    scanf("%d", &m);
    int player_scores[m]; 
    printf("Enter the player's scores: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &player_scores[i]);
    }
    int ranks[m];  
        for (int i = 0; i < m; i++) {
        int player_score = player_scores[i];
        int rank = 1; 
        int last_leaderboard_score = -1;    
        for (int j = 0; j < n; j++) {
            if (leaderboard[j] != last_leaderboard_score) {
                last_leaderboard_score = leaderboard[j];
                rank++;
            }
            if (player_score >= leaderboard[j]) {
                rank--;
                break;
            }
        }
        ranks[i] = rank; 
    }
    printf("Player's ranks after each score: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", ranks[i]);
    }
    printf("\n");
    return 0;
}
