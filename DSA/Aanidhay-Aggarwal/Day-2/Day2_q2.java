import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of scores on leaderboard: ");
        int n = scanner.nextInt();
        int[] leaderboard = new int[n];
        System.out.print("Enter leaderboard scores: ");
        for (int i = 0; i < n; i++) {
            leaderboard[i] = scanner.nextInt();
        }

        System.out.print("Enter number of player scores: ");
        int m = scanner.nextInt();
        int[] player_scores = new int[m];
        System.out.print("Enter player scores: ");
        for (int i = 0; i < m; i++) {
            player_scores[i] = scanner.nextInt();
        }
        scanner.close();

        int[] ranks = new int[m];

        for (int i = 0; i < m; i++) {
            int player_score = player_scores[i];
            int rank = 1;

            for (int j = 0; j < n; j++) {
                if (player_score >= leaderboard[j]) {
                    break;
                }
                if (j > 0 && leaderboard[j] == leaderboard[j - 1]) {
                    continue;  
                }
                rank++;
            }

            ranks[i] = rank;
        }

        for (int rank : ranks) {
            System.out.print(rank + " ");
        }
    }
}
