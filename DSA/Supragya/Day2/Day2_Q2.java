/**
 * Question 2: 
 * A player is climbing a leaderboard where scores are ranked in descending order. 
 * Given the scores on the leaderboard and the player's scores in the game, determine the 
 * player's rank after each new score.
 * 
 * Inputs:
 * An array of integers representing the leaderboard scores.
 * An array of integers representing the player's scores. 
 * 
 * Output:
 * An array of integers representing the player's rank after each new score.
 * 
 * Example:
 * leaderboard = [100, 90, 90, 80]
 * player_scores = [70, 80, 105]
 * 
 * Output: [4, 3, 1]
 */
import java.util.*;
public class Day2_Q2 {
    public static ArrayList<Integer> Rank(ArrayList<Integer> leaderboard, ArrayList<Integer> score){
        ArrayList<Integer> ranks = new ArrayList<>();
        HashSet<Integer> set = new HashSet<>(leaderboard);
        leaderboard= new ArrayList<>(set);
        Collections.sort(leaderboard, Collections.reverseOrder());
        for(int i=0;i<score.size();i++){
            for(int j : leaderboard){
                if(score.get(i)<leaderboard.get(leaderboard.size()-1)){
                    ranks.add(leaderboard.size()+1);
                    break;
                }
                else if(j<=score.get(i)){
                    ranks.add(leaderboard.indexOf(j)+1);
                    break;
                }
            }
        }
        return ranks;
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        ArrayList<Integer> leaderboard = new ArrayList<>();
        ArrayList<Integer> score = new ArrayList<>();
        int n = scan.nextInt();
        for(int i=0;i<n;i++){
            leaderboard.add(scan.nextInt());
        }
        n = scan.nextInt();
        for(int i=0;i<n;i++){
            score.add(scan.nextInt());
        }
        System.out.println("Player Ranks: "+Rank(leaderboard, score));
    }
}
