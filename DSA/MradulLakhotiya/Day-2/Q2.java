import java.util.*;

public class Q2 {
    public static void main(String[] args) {
        int[] ranked = {100, 90, 90, 80};
        int[] player = {70, 80, 105};
        
        int[] result = climbingLeaderboard(ranked, player);
        
        System.out.print("Player Ranks: ");
        for (int rank : result) {
            System.out.print(rank + " ");
        }
        System.out.println();  // Output: Player Ranks: 4 3 1
    }
    
    public static int[] climbingLeaderboard(int[] ranked, int[] player) {
        List<Integer> finalRank = new ArrayList<>();
        
        // Remove duplicates and sort in descending order
        Set<Integer> set = new TreeSet<>(Collections.reverseOrder());
        for (int score : ranked) {
            set.add(score);
        }
        
        // Convert set to array
        Integer[] uniqueArray = set.toArray(new Integer[set.size()]);
        
        for (int i = 0; i < player.length; i++) {
            if (i != 0 && player[i] <= player[i - 1]) {
                finalRank.add(finalRank.get(finalRank.size() - 1));
            } else {
                int rank = binarySearch(uniqueArray, player[i]);
                finalRank.add(rank + 1);
            }
        }
        
        // Convert List<Integer> to int[]
        int[] result = new int[finalRank.size()];
        for (int j = 0; j < finalRank.size(); j++) {
            result[j] = finalRank.get(j);
        }
        
        return result;
    }
    
    // Binary search function
    private static int binarySearch(Integer[] ranked, int p) {
        int lo = 0;
        int hi = ranked.length - 1;
        
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (ranked[mid] <= p) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
}
