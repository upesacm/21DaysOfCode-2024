import java.io.*;
import java.util.*;

public class Solution3 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in);
        
        // Read number of stations
        int n = scanner.nextInt();
        
        // Read station positions
        int[] stations = new int[n];
        for (int i = 0; i < n; i++) {
            stations[i] = scanner.nextInt();
        }
        
        // Read number of properties to buy
        int p = scanner.nextInt();
        
        // Calculate minimum cost
        int minCost = findMinimumCost(stations, p);
        
        // Output the result
        System.out.println(minCost);
        
        scanner.close();
    }

    public static int findMinimumCost(int[] stations, int p) {
        Arrays.sort(stations); // Sort stations array
        
        int left = 0;
        int right = stations[stations.length - 1] - stations[0];
        int minCost = Integer.MAX_VALUE;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canPlaceProperties(stations, p, mid)) {
                minCost = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return minCost;
    }
    
    private static boolean canPlaceProperties(int[] stations, int p, int maxDistance) {
        int count = 1; // Start with the first station
        int lastPosition = stations[0];
        
        for (int i = 1; i < stations.length; i++) {
            if (stations[i] - lastPosition >= maxDistance) {
                count++;
                lastPosition = stations[i];
                if (count == p) {
                    return true;
                }
            }
        }
        
        return false;
    }
}