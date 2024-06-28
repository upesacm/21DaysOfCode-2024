import java.io.*;
import java.util.*;

public class Solution2 {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
       Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        System.out.println(minCost(str));
    }

    public static int minCost(String str) {
        int n = str.length();
        int totalX = 0;
        int totalY = 0;

        // Count total 'x' and 'y' characters in the string
        for (int i = 0; i < n; i++) {
            if (str.charAt(i) == 'x') {
                totalX++;
            } else if (str.charAt(i) == 'y') {
                totalY++;
            }
        }

        int minCost = Integer.MAX_VALUE;
        int currentX = 0;
        int currentY = 0;

        // Traverse the string and calculate minCost
        for (int i = 0; i < n; i++) {
            char c = str.charAt(i);
            if (c == 'x') {
                currentX++;
            } else if (c == 'y') {
                currentY++;
            }
            
            int remainingX = totalX - currentX;
            int removedY = currentY;
            
            minCost = Math.min(minCost, Math.max(remainingX, removedY));
        }

        return minCost;
    }
}