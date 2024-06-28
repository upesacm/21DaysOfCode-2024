import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] stations = new int[n];
        
        for (int i = 0; i < n; i++) {
            stations[i] = scanner.nextInt();
        }
        
        int p = scanner.nextInt();
        
        System.out.println(minCostToBuyProperties(stations, p));
    }
    
    public static int minCostToBuyProperties(int[] stations, int p) {
        Arrays.sort(stations);
        
        // Binary search on the answer
        int left = 0;
        int right = 200000000;
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceProperties(mid, stations, p)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        // Calculate the total cost for the found result
        return calculateTotalCost(result, stations, p);
    }
    
    // Check if we can place p properties with max distance maxDist
    private static boolean canPlaceProperties(int maxDist, int[] stations, int p) {
        int count = 0;
        int i = 0;
        
        while (i < stations.length) {
            count++; // Place a property at the current station
            int location = stations[i] + maxDist;
            
            // Move to the next station that is at least maxDist away
            while (i < stations.length && stations[i] <= location) {
                i++;
            }
            
            if (count >= p) {
                return true;
            }
        }
        
        return false;
    }
    
    // Calculate the total cost for placing p properties with max distance maxDist
    private static int calculateTotalCost(int maxDist, int[] stations, int p) {
        int totalCost = 0;
        
        // Place properties and calculate costs
        for (int i = 0; i < p; i++) {
            int nearestStation = findNearestStation(maxDist, stations);
            totalCost += Math.abs(nearestStation - maxDist);
        }
        
        return totalCost;
    }
    
    // Find nearest station within maxDist range
    private static int findNearestStation(int maxDist, int[] stations) {
        int minDistance = Integer.MAX_VALUE;
        int nearestStation = 0;
        
        for (int station : stations) {
            int distance = Math.abs(station - maxDist);
            if (distance < minDistance) {
                minDistance = distance;
                nearestStation = station;
            }
        }
        
        return nearestStation;
    }
}
