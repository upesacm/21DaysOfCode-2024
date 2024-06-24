import java.util.*;

class Day2 {
    void rank(int[] leaderboard, int[] playerScores) {
        // Remove duplicates and keep the leaderboard in descending order
        ArrayList<Integer> distinctLeaderboard = new ArrayList<>();
        distinctLeaderboard.add(leaderboard[0]);
        for (int i = 1; i < leaderboard.length; i++) {
            if (leaderboard[i] != leaderboard[i - 1]) {
                distinctLeaderboard.add(leaderboard[i]);
            }
        }

        int[] ranks = new int[playerScores.length];

        for (int i = 0; i < playerScores.length; i++) {
            int score = playerScores[i];
            int rank = 1;
            boolean placed = false;
            
            for (int j = 0; j < distinctLeaderboard.size(); j++) {
                if (score >= distinctLeaderboard.get(j)) {
                    ranks[i] = rank;
                    placed = true;
                    break;
                } else {
                    rank++;
                }
            }

            if (!placed) {
                ranks[i] = rank;
            }
        }

        // Print the ranks
        System.out.println("Player Ranks:");
        for (int i = 0; i < ranks.length; i++) {
            System.out.print(ranks[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Size of leaderboard: ");
        int n = sc.nextInt();
        int[] leaderboard = new int[n];
        System.out.println("Enter scores in leaderboard in descending order:");
        for (int i = 0; i < n; i++) {
            leaderboard[i] = sc.nextInt();
        }

        System.out.print("Number of player scores: ");
        int m = sc.nextInt();
        int[] playerScores = new int[m];
        System.out.println("Enter player scores:");
        for (int i = 0; i < m; i++) {
            playerScores[i] = sc.nextInt();
        }

        Day2 obj = new Day2();
        obj.rank(leaderboard, playerScores);

        sc.close();
    }
}
