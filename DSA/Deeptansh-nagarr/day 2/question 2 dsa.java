import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class LeaderboardRanking {

    public static int[] calculatePlayerRanks(int[] leaderboard, int[] playerScores) {
        int[] uniqueLeaderboard = Arrays.stream(leaderboard).distinct().toArray();
        
        int[] playerRanks = new int[playerScores.length];
        
        int index = uniqueLeaderboard.length - 1; 
        for (int i = 0; i < playerScores.length; i++) {
            while (index >= 0 && playerScores[i] >= uniqueLeaderboard[index]) {
                index--;
            }
            playerRanks[i] = index + 2; 
        }
        
        return playerRanks;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.println("Enter the number of leaderboard scores:");
        int n = scanner.nextInt();
        int[] leaderboard = new int[n];
        System.out.println("Enter the leaderboard scores:");
        for (int i = 0; i < n; i++) {
            leaderboard[i] = scanner.nextInt();
        }
        System.out.println("Enter the number of player scores:");
        int m = scanner.nextInt();
        int[] playerScores = new int[m];
        System.out.println("Enter the player scores:");
        for (int i = 0; i < m; i++) {
            playerScores[i] = scanner.nextInt();
        }
        
        // Calculate the player's ranks
        int[] playerRanks = calculatePlayerRanks(leaderboard, playerScores);
        
        System.out.println("Player ranks after each score:");
        for (int rank : playerRanks) {
            System.out.println(rank);
        }
    }
}
