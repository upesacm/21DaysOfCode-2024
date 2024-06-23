import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ClimbingLeaderboard {
    public static int[] climbingLeaderboard(int[] leaderboard, int[] playerScores) {
        // Remove duplicates from leaderboard
        List<Integer> uniqueLeaderboard = new ArrayList<>();
        for (int score : leaderboard) {
            if (uniqueLeaderboard.isEmpty() || uniqueLeaderboard.get(uniqueLeaderboard.size() - 1) != score) {
                uniqueLeaderboard.add(score);
            }
        }

        int[] ranks = new int[playerScores.length];
        int rankIndex = uniqueLeaderboard.size() - 1;
        
        for (int i = 0; i < playerScores.length; i++) {
            while (rankIndex >= 0 && playerScores[i] >= uniqueLeaderboard.get(rankIndex)) {
                rankIndex--;
            }
            ranks[i] = rankIndex + 2;  // +2 because rankIndex is zero-based and rank starts from 1
        }
        return ranks;
    }

    public static void main(String[] args) {
        int[] leaderboard = {100, 90, 90, 80};
        int[] playerScores = {70, 80, 105};
        System.out.println(Arrays.toString(climbingLeaderboard(leaderboard, playerScores)));  // Output: [4, 3, 1]
    }
}
