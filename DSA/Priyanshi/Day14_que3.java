import java.io.*;
import java.util.*;

public class Solution {
    static class Bulb implements Comparable<Bulb> {
        int start, end;
        
        Bulb(int start, int end) {
            this.start = start;
            this.end = end;
        }
        
        public int compareTo(Bulb other) {
            if (this.start == other.start) {
                return other.end - this.end; // Prefer bulbs with larger range
            }
            return this.start - other.start;
        }
    }
    
    public static int minBulbsToLightHallway(int n, int[] hallway) {
        List<Bulb> bulbs = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            if (hallway[i] != -1) {
                int power = hallway[i];
                int start = Math.max(0, i - power);
                int end = Math.min(n - 1, i + power);
                bulbs.add(new Bulb(start, end));
            }
        }
        
        Collections.sort(bulbs);
        
        int endCovered = -1;
        int farthest = 0;
        int bulbCount = 0;
        int i = 0;
        
        while (endCovered < n - 1) {
            while (i < bulbs.size() && bulbs.get(i).start <= endCovered + 1) {
                farthest = Math.max(farthest, bulbs.get(i).end);
                i++;
            }
            
            if (endCovered == farthest) {
                return -1;
            }
            
            endCovered = farthest;
            bulbCount++;
        }
        
        return bulbCount;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] hallway = new int[n];
        for (int i = 0; i < n; i++) {
            hallway[i] = sc.nextInt();
        }
        sc.close();
        
        System.out.println(minBulbsToLightHallway(n, hallway));
    }
}
