//Question-2
//Author: Ayush Dey

import java.util.*;

public class LeaderboardClimbing {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of players on the leaderboard: ");
        int n = scanner.nextInt();
        int[] ranked = new int[n];
        for (int i = 0; i < n; i++) {
            ranked[i] = scanner.nextInt();
        }

        System.out.print("Enter the number of games played by the player: ");
        int m = scanner.nextInt();
        int[] player = new int[m];
        for (int i = 0; i < m; i++) {
            player[i] = scanner.nextInt();
        }

       
        int[] uniqueRanked = createUniqueLeaderboard(ranked);

        int[] playerRank = calculatePlayerRank(uniqueRanked, player);

        // Output format
        for (int rank : playerRank) {
            System.out.print(rank + " ");
        }

        scanner.close();
    }

    // Function to create a unique leaderboard
    private static int[] createUniqueLeaderboard(int[] ranked) {
        List<Integer> uniqueList = new ArrayList<>();
        for (int score : ranked) {
            if (uniqueList.isEmpty() || score != uniqueList.get(uniqueList.size() - 1)) {
                uniqueList.add(score);
            }
        }
        return uniqueList.stream().mapToInt(Integer::intValue).toArray();
    }

    // Function to calculate player's rank after each new score
    private static int[] calculatePlayerRank(int[] uniqueRanked, int[] player) {
        int[] playerRank = new int[player.length];
        int pointer = uniqueRanked.length - 1;

        for (int i = 0; i < player.length; i++) {
            while (pointer >= 0 && player[i] >= uniqueRanked[pointer]) {
                pointer--;
            }
            playerRank[i] = pointer + 2;
        }

        return playerRank;
    }
}
