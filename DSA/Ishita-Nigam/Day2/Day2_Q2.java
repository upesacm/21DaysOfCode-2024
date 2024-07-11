import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Day2_Q2 {

    public static int[] climbingLeaderboard(int[] leaderboard, int[] playerScores) {
        // Remove duplicates and maintain the leaderboard in descending order
        List<Integer> distinctLeaderboard = new ArrayList<>();
        distinctLeaderboard.add(leaderboard[0]);
        for (int i = 1; i < leaderboard.length; i++) {
            if (leaderboard[i] != leaderboard[i - 1]) {
                distinctLeaderboard.add(leaderboard[i]);
            }
        }

        int[] result = new int[playerScores.length];
        int index = distinctLeaderboard.size() - 1;

        // Determine the rank for each player's score
        for (int i = 0; i < playerScores.length; i++) {
            while (index >= 0 && playerScores[i] >= distinctLeaderboard.get(index)) {
                index--;
            }
            result[i] = index + 2; // rank is 1-based index, hence adding 2
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        System.out.println("Enter the leaderboard scores:");
        String[] leaderboardInput = in.nextLine().split(" ");
        int[] leaderboard = new int[leaderboardInput.length];
        for (int i = 0; i < leaderboardInput.length; i++) {
            leaderboard[i] = Integer.parseInt(leaderboardInput[i]);
        }

        System.out.println("Enter the player's scores:");
        String[] playerScoresInput = in.nextLine().split(" ");
        int[] playerScores = new int[playerScoresInput.length];
        for (int i = 0; i < playerScoresInput.length; i++) {
            playerScores[i] = Integer.parseInt(playerScoresInput[i]);
        }

        int[] result = climbingLeaderboard(leaderboard, playerScores);

        System.out.println("Player's ranks after each score:");
        for (int rank : result) {
            System.out.print(rank + " ");
        }

        in.close();
    }
}
