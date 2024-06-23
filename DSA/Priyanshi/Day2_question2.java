import java.util.*;
public class Day2_question2 {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter the number of leaderboard scores:");
            int n = sc.nextInt();
            int[] leaderboard = new int[n];
            System.out.println("Enter the leaderboard scores:");
            for (int i = 0; i < n; i++) {
                leaderboard[i] = sc.nextInt();
            }
            System.out.println("Enter the number of player scores:");
            int m = sc.nextInt();
            int[] player_scores = new int[m];
            System.out.println("Enter the player scores:");
            for (int i = 0; i < m; i++) {
                player_scores[i] = sc.nextInt();
            }
            int[] ranks = climbingLeaderboard(leaderboard, player_scores);
            System.out.println("Ranks:");
            for (int rank : ranks) {
                System.out.print(rank + " ");
            }
        }
    
        public static int[] climbingLeaderboard(int[] leaderboard, int[] player_scores) {
            int[] ranks = new int[player_scores.length];
            for (int i = 0; i < player_scores.length; i++) {
                int rank = 1;
                for (int j = 0; j < leaderboard.length; j++) {
                    if (player_scores[i] < leaderboard[j]) {
                        rank++;
                    }
                }
                ranks[i] = rank;
            }
            return ranks;
        }
    }
