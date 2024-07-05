import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] heights = new int[n];
        for (int i = 0; i < n; i++) {
            heights[i] = scanner.nextInt();
        }
        
        int moves = 0;
        for (int i = 1; i < n; i++) {
            if (heights[i] < heights[i - 1]) {
                moves++;
                while (i < n && heights[i] < heights[i - 1]) {
                    heights[i] = heights[i - 1]; 
                    i++;
                }
            }
        }

        System.out.println(moves);
    }
}
