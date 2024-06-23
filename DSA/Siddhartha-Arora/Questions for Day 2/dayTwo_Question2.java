
/*
##### Question 2: A player is climbing a leaderboard where scores are ranked in descending order. Given the scores on the leaderboard and the player's scores in the game, determine the player's rank after each new score.
Inputs:
- An array of integers representing the leaderboard scores.
-	An array of integers representing the player's scores.
Output:
-	An array of integers representing the player's rank after each new score.

Example:

leaderboard = [100, 90, 90, 80]

player_scores = [70, 80, 105]

Output: [4, 3, 1]


*/

import java.util.*;

public class dayTwo_Question2 {
    public static void main(String[] args) {
        List<Integer> leaderboard = Arrays.asList(100, 90, 90, 80, 75, 60);
        List<Integer> playerScores = Arrays.asList(50, 65, 77, 90, 102);
        
        List<Integer> result = calculateRanks(leaderboard, playerScores);
        
        System.out.println(result); // Output: [6, 5, 4, 2, 1]
    }

    public static List<Integer> calculateRanks(List<Integer> leaderboard, List<Integer> playerScores) {
        Set<Integer> set = new TreeSet<>(leaderboard); 

        List<Integer> list = new ArrayList<>(set);
        Collections.reverse(list); 

        List<Integer> res = new ArrayList<>();
        int end = list.size() - 1;

        for (int score : playerScores) {
            while (end >= 0 && score >= list.get(end)) {
                end--;
            }
            res.add(end + 2); 
        }

        return res;
    }
}
