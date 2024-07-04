import java.io.*;
import java.util.*;

public class Solution {
    public static int minMovesToSort(int[] heights) {
        int moves = 0;
        while (true) {
            boolean removed = false;
            List<Integer> newHeights = new ArrayList<>();
            newHeights.add(heights[0]);
            for (int i = 1; i < heights.length; i++) {
                if (heights[i] >= heights[i - 1]) {
                    newHeights.add(heights[i]);
                } else {
                    removed = true;
                }
            }
            if (!removed) {
                break;
            }
            heights = newHeights.stream().mapToInt(i -> i).toArray();
            moves += 1;
        }
        return moves;
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();
        int[] heights = new int[n];
        
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
        
        System.out.println(minMovesToSort(heights));
        
        scanner.close();
    }
}