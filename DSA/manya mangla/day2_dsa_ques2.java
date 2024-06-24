import java.util.Arrays;
import java.util.TreeSet;

public class PlayerRanking {

    public static int[] climbingLeaderboard(int[] leaderboard, int[] playerScores) {
        // Use a TreeSet to store unique leaderboard scores in descending order
        TreeSet<Integer> uniqueScores = new TreeSet<>((a, b) -> b - a);
        for (int score : leaderboard) {
            uniqueScores.add(score);
        }

        // Convert TreeSet to array for binary search
        Integer[] uniqueScoresArray = uniqueScores.toArray(new Integer[0]);

        int[] ranks = new int[playerScores.length];
        int n = uniqueScoresArray.length;

        // Binary search to find rank for each player score
        for (int i = 0; i < playerScores.length; i++) {
            int score = playerScores[i];
            int pos = Arrays.binarySearch(uniqueScoresArray, score, (a, b) -> b - a);

            if (pos >= 0) {
                // Found exact score in leaderboard
                ranks[i] = pos + 1;
            } else {
                // Score not found, calculate the rank as the position to insert + 1
                pos = -(pos + 1);
                ranks[i] = pos + 1;
            }
        }

        return ranks;
    }

    public static void main(String[] args) {
        int[] leaderboard = {100, 90, 90, 80};
        int[] playerScores = {70, 80, 105};

        int[] ranks = climbingLeaderboard(leaderboard, playerScores);

        // Output: [4, 3, 1]
        for (int rank : ranks) {
            System.out.println(rank);
        }
    }
}
