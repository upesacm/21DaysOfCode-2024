import java.util.*;

public class Solution3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] hallway = new int[n];
        
        for (int i = 0; i < n; i++) {
            hallway[i] = scanner.nextInt();
        }
        
        int minBulbs = minBulbsToLightUp(n, hallway);
        System.out.println(minBulbs);
        
        scanner.close();
    }
    
    public static int minBulbsToLightUp(int n, int[] hallway) {
        // Edge case: If there are no partitions, return -1
        if (n == 0) {
            return -1;
        }
        
        // Create an array to store the farthest reach of each bulb
        int[] lights = new int[n];
        Arrays.fill(lights, -1); // Initialize all positions to -1
        
        // Fill the lights array based on the given hallway array
        for (int i = 0; i < n; i++) {
            if (hallway[i] != -1) {
                int reach = hallway[i];
                int left = Math.max(0, i - reach);
                int right = Math.min(n - 1, i + reach);
                lights[left] = Math.max(lights[left], right);
            }
        }
        
        // Now use a greedy algorithm to place bulbs
        int bulbsCount = 0;
        int i = 0;
        
        while (i < n) {
            if (lights[i] == -1) {
                return -1; // There's a gap that cannot be covered
            }
            bulbsCount++;
            i = lights[i] + 1; // Move to the next uncovered position
        }
        
        return bulbsCount;
    }
}
