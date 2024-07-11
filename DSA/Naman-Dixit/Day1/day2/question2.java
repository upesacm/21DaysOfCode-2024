import java.util.ArrayList;
import java.util.Arrays;

public class Leaderboard {

    public static void main(String[] args) {
        // Example input data
        int[] leaderboardScores = {500, 483, 359,200,157,120, 90};
        int[] playerScores = {6, 7,10,18,189};

        // Get player ranks
        int[] playerRanks = climbingLeaderboard(leaderboardScores, playerScores);

        // Output results
        System.out.println("Player ranks after each score:");
        System.out.println(Arrays.toString(playerRanks));
    }

    public static int[] climbingLeaderboard(int[] leaderboardScores, int[] playerScores) {
        // Remove duplicates and store unique leaderboard scores
        ArrayList<Integer> uniqueLeaderboardScores = new ArrayList<>();
        uniqueLeaderboardScores.add(leaderboardScores[0]);

        for (int i = 1; i < leaderboardScores.length; i++) {
            if (leaderboardScores[i] != leaderboardScores[i - 1]) {
                uniqueLeaderboardScores.add(leaderboardScores[i]);
            }
        }

        // Array to store player ranks
        int[] playerRanks = new int[playerScores.length];
        int index = uniqueLeaderboardScores.size() - 1;

        // Determine ranks for each player's score
        for (int i = 0; i < playerScores.length; i++) {
            while (index >= 0 && playerScores[i] >= uniqueLeaderboardScores.get(index)) {
                index--;
            }
            playerRanks[i] = index + 2;  // Rank is index + 2
        }

        return playerRanks;
    }
}
