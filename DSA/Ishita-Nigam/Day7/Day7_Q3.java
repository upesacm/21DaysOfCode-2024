import java.util.Arrays;
import java.util.Scanner;

public class Day7_Q3 {
    // Function to check if it's possible to buy 'p' properties with a maximum cost
    // of 'maxCost'
    public static boolean isPossible(int[] stations, int p, int maxCost) {
        int count = 0;
        for (int pos = Integer.MIN_VALUE; pos <= Integer.MAX_VALUE; pos++) {
            // Find the nearest police station to the current position
            int minDist = Integer.MAX_VALUE;
            for (int station : stations) {
                minDist = Math.min(minDist, Math.abs(pos - station));
                if (minDist <= maxCost) {
                    break;
                }
            }
            if (minDist <= maxCost) {
                count++;
            }
            if (count >= p) {
                return true;
            }
        }
        return false;
    }

    public static int minCostToBuyProperties(int[] stations, int p) {
        int left = 0;
        int right = Integer.MAX_VALUE;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(stations, p, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] stations = new int[n];
        for (int i = 0; i < n; i++) {
            stations[i] = scanner.nextInt();
        }

        int p = scanner.nextInt();
        System.out.println(minCostToBuyProperties(stations, p));

        scanner.close();
    }
}
