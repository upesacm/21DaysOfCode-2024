import java.util.*;

public class LeaderboardRanking {
    public static int[] calculatePlayerRanks(int[] leaderboard, int[] playerScores) {
        TreeSet<Integer> uniqueScores = new TreeSet<>(Comparator.reverseOrder());
        for (int score : leaderboard) {
            uniqueScores.add(score);
        }
        
        int[] ranks = new int[playerScores.length];
        
        for (int i = 0; i < playerScores.length; i++) {
            uniqueScores.add(playerScores[i]);
            ranks[i] = uniqueScores.headSet(playerScores[i]).size() + 1;
        }
        
        return ranks;
    }

    public static void main(String[] args) {
        int[] leaderboard = {100, 90, 90, 80};
        int[] playerScores = {70, 80, 105};
        int[] ranks = calculatePlayerRanks(leaderboard, playerScores);
        System.out.println("Leaderboard: " + Arrays.toString(leaderboard));
        System.out.println("Player scores: " + Arrays.toString(playerScores));
        System.out.println("Player ranks after each game: " + Arrays.toString(ranks));
    }
}
