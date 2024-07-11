/*
Question 2: A player is climbing a leaderboard where scores are ranked in descending order. Given the scores on the leaderboard and the player's scores in the game, determine the player's rank after each new score.
Inputs:

An array of integers representing the leaderboard scores.
An array of integers representing the player's scores. Output:
An array of integers representing the player's rank after each new score.
Example:

leaderboard = [100, 90, 90, 80]

player_scores = [70, 80, 105]

Output: [4, 3, 1]
*/

#include <stdio.h>
#include <stdlib.h>

// Function to remove duplicates and return the count of unique scores
int remove_duplicates(int *scores, int n, int *unique_scores) {
    if (n == 0) return 0;
    int j = 0;
    unique_scores[j] = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] != scores[j]) {
            j++;
            unique_scores[j] = scores[i];
        }
    }
    return j + 1;
}

// Function to determine the rank of each player's score
void climbing_leaderboard(int *leaderboard, int leaderboard_size, int *player_scores, int player_size, int *result) {
    int unique_leaderboard[leaderboard_size];
    int unique_count = remove_duplicates(leaderboard, leaderboard_size, unique_leaderboard);

    for (int i = 0; i < player_size; i++) {
        int rank = 1;
        for (int j = 0; j < unique_count; j++) {
            if (player_scores[i] >= unique_leaderboard[j]) {
                break;
            }
            rank++;
        }
        result[i] = rank;
    }
}

int main() {
    int leaderboard_size, player_size;

    // Get leaderboard size and scores from the user
    printf("Enter the size of the leaderboard: ");
    scanf("%d", &leaderboard_size);
    int *leaderboard = (int *)malloc(leaderboard_size * sizeof(int));
    printf("Enter the leaderboard scores in descending order:\n");
    for (int i = 0; i < leaderboard_size; i++) {
        scanf("%d", &leaderboard[i]);
    }

    // Get player scores size and scores from the user
    printf("Enter the number of player scores: ");
    scanf("%d", &player_size);
    int *player_scores = (int *)malloc(player_size * sizeof(int));
    printf("Enter the player scores:\n");
    for (int i = 0; i < player_size; i++) {
        scanf("%d", &player_scores[i]);
    }

    // Array to store the result
    int *result = (int *)malloc(player_size * sizeof(int));

    // Calculate the ranks
    climbing_leaderboard(leaderboard, leaderboard_size, player_scores, player_size, result);

    // Print the results
    printf("Player ranks after each score:\n");
    for (int i = 0; i < player_size; i++) {
        printf("%d\n", result[i]);
    }

    // Free allocated memory
    free(leaderboard);
    free(player_scores);
    free(result);

    return 0;
}

