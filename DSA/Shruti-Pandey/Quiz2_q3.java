import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] hallway = new int[n];
        for (int i = 0; i < n; i++) {
            hallway[i] = sc.nextInt();
        }
        
        int result = minBulbsToLightHallway(n, hallway);
        
        System.out.println(result);
    }
    
    public static int minBulbsToLightHallway(int n, int[] hallway) {
        List<int[]> bulbs = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            if (hallway[i] != -1) {
                int range = hallway[i];
                bulbs.add(new int[]{i - range, i + range});
            }
        }
      
        Collections.sort(bulbs, (a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        
        int count = 0;
        int end = 0;
        int i = 0;
        while (end < n) {
            int farthest = -1;
            while (i < bulbs.size() && bulbs.get(i)[0] <= end) {
                farthest = Math.max(farthest, bulbs.get(i)[1]);
                i++;
            }
            
            if (farthest == -1) {
                return -1;
            }
            
            count++;
            end = farthest + 1;
        }
        
        return count;
    }
}
