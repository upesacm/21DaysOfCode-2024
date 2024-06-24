import java.util.*;

public class Day_2_Question_2 {
    
    public static int[] playerRanks(int leaderboard[], int playerScores[]) {
        
        // I am converting this to hashset to remove duplicates
        // I did try to do it manually but it was hard so I why not just use hashsets
        HashSet<Integer> seen = new HashSet<Integer>();
        for (int i: leaderboard)
            seen.add(i);
        
        List<Integer> newLeaderboard = new ArrayList<Integer>();
        for (int i: seen)
            newLeaderboard.add(i);
        
        int resArray[] = new int[playerScores.length];
        int index = 0;
        for (int i: playerScores) {
            if (!newLeaderboard.contains(i)) {
                newLeaderboard.add(i);
            }
            Collections.sort(newLeaderboard, Collections.reverseOrder());
            resArray[index] = newLeaderboard.indexOf(i) + 1;
            ++index;
        }
        return resArray;
    }
    public static void main(String[] args) {
        int []arr1 = {100, 90, 90, 80};
        int []arr2 = {70, 80, 105};
        int res[] = playerRanks(arr1, arr2);
        for (int i=0; i < res.length; i++) {
            System.out.printf("%d ", res[i]);
        }
    }
}
