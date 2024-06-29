import java.io.*;

public class Solution {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine().trim();
        
        int result = minOperations(str);
        
        System.out.println(result);
    }
    
    public static int minOperations(String str) {
        int n = str.length();
        
        // Count total 'x' and 'y' in the string
        int count_x = 0;
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == 'x') {
                count_x++;
            }
        }
        int count_y = n - count_x; // total count - count_x gives count_y
        
        // Initialize variables to keep track of minimum operations
        int min_operations = Integer.MAX_VALUE;
        int current_y_removed = 0; // number of 'y' characters removed
        
        // Iterate through the string
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == 'y') {
                current_y_removed++;
            }
            
            // Calculate remaining 'x' characters and removed 'y' characters
            int remaining_x = count_x - (i + 1 - current_y_removed);
            int removed_y = current_y_removed;
            
            // Calculate max(dig0, dig1)
            int max_dig = Math.max(remaining_x, removed_y);
            
            // Update the minimum operations found
            min_operations = Math.min(min_operations, max_dig);
        }
        
        return min_operations;
    }
}
