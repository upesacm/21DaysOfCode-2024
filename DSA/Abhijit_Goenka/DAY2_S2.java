/*
 A player is climbing a leaderboard where scores are ranked in descending order. Given the scores on the leaderboard and the player's scores in the game, determine the player's rank after each new score.
Inputs:

An array of integers representing the leaderboard scores.
An array of integers representing the player's scores. Output:
An array of integers representing the player's rank after each new score.
Example:

leaderboard = [100, 90, 90, 80]

player_scores = [70, 80, 105]

Output: [4, 3, 1]
 */

 import java.util.Arrays;
 class DAY2_S2 
 {
     public static void main(String[] args) 
     {
         
         int[] leaderboard = {100, 90, 90, 80};
         int[] playerScores = {70, 80, 105};
 
         int[] playerRanks = getPlayerRanks(leaderboard, playerScores);
         System.out.println(Arrays.toString(playerRanks)); // Output: [4, 3, 1]
     }
 
     public static int[] getPlayerRanks(int[] leaderboard, int[] playerScores) {
         int[] uniqueScores = getUniqueScores(leaderboard);
         
         
         int[] playerRanks = new int[playerScores.length];
 
         for (int i = 0; i < playerScores.length; i++) {
             int score = playerScores[i];
             int rank = 1; 
             for (int uniqueScore : uniqueScores) 
             {
                 if (score < uniqueScore) 
                 {
                     rank++;
                 } else 
                 {
                     break; 
                 }
             }
 
             
             playerRanks[i] = rank;
         }
 
         return playerRanks;
     }
 
     private static int[] getUniqueScores(int[] scores) 
     {
         
         Arrays.sort(scores);
         int n = scores.length;
         
         
         int uniqueCount = 0;
         for (int i = 0; i < n; i++) {
             if (i == 0 || scores[i] != scores[i - 1]) 
             {
                 uniqueCount++;
             }
         }
         int[] uniqueScores = new int[uniqueCount];
         int index = 0;
         for (int i = n - 1; i >= 0; i--) {
             if (i == n - 1 || scores[i] != scores[i + 1]) 
             {
                 uniqueScores[index++] = scores[i];
             }
         }
 
         return uniqueScores;
     }
 }
 