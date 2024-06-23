#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int leaderboard[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &leaderboard[i]);
    }

    int player_scores[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &player_scores[i]);
    }

    int ranks[m];
    for (int i = 0; i < m; i++) {
        int rank = 1;
        for (int j = 0; j < n; j++) {
            if (leaderboard[j] > player_scores[i]) {
                rank++;
            }
        }
        ranks[i] = rank;
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", ranks[i]);
    }
    printf("\n");

    return 0;
}
