import java.util.*;

public class Day2_Solution2 {

    public static int[] getPlayerRanks(int[] leaderboard, int[] playerScores) {
        // Remove duplicates and sort in descending order
        TreeSet<Integer> sortedScores = new TreeSet<>(Collections.reverseOrder());
        for (int score : leaderboard) {
            sortedScores.add(score);
        }

        // Convert to list
        List<Integer> distinctLeaderboard = new ArrayList<>(sortedScores);

        int[] result = new int[playerScores.length];

        for (int i = 0; i < playerScores.length; i++) {
            result[i] = getRank(distinctLeaderboard, playerScores[i]);
        }

        return result;
    }

    private static int getRank(List<Integer> distinctLeaderboard, int playerScore) {
        int left = 0;
        int right = distinctLeaderboard.size() - 1;

        // Binary search to find the position
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (distinctLeaderboard.get(mid) == playerScore) {
                return mid + 1;
            } else if (distinctLeaderboard.get(mid) > playerScore) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + 1;
    }

    public static void main(String[] args) {
        int[] leaderboard = {100, 90, 90, 80};
        int[] playerScores = {70, 80, 105};

        int[] ranks = getPlayerRanks(leaderboard, playerScores);

        // Print the ranks
        System.out.println(Arrays.toString(ranks)); // Output: [4, 3, 1]
    }
}
