
import java.util.*;

public class Day14_Solution3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] hallway = new int[n];
        for (int i = 0; i < n; i++) {
            hallway[i] = scanner.nextInt();
        }

        // Arrays to store the furthest reach to the left and right for each bulb
        int[] left = new int[n];
        int[] right = new int[n];

        // Initialize left and right arrays based on given bulb ranges
        for (int i = 0; i < n; i++) {
            if (hallway[i] != -1) {
                int start = Math.max(0, i - hallway[i]);
                int end = Math.min(n - 1, i + hallway[i]);
                left[end] = Math.max(left[end], start);
                right[start] = Math.max(right[start], end);
            }
        }

        int bulbs = 0;
        int position = 0;

        while (position < n) {
            if (right[position] < position) {
                // If no bulb can cover this position
                System.out.println(-1);
                return;
            }
            bulbs++;
            position = right[position] + 1; // Move to the next position beyond the reach of current bulb
        }

        System.out.println(bulbs);
    }
}
