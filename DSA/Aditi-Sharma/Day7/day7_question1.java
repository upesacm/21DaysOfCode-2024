import java.util.Arrays;
import java.util.Scanner;

public class MinimumPropertyCost {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] station = new int[n];
        for (int i = 0; i < n; i++) {
            station[i] = scanner.nextInt();
        }
        int p = scanner.nextInt();

        System.out.println(minimumCost(n, station, p));
    }

    public static int minimumCost(int n, int[] station, int p) {
        Arrays.sort(station);

        int left = 0;
        int right = Integer.MAX_VALUE;
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlaceProperties(mid, n, station, p)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

    private static boolean canPlaceProperties(int maxDist, int n, int[] station, int p) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            int start = station[i] - maxDist;
            int end = station[i] + maxDist;

            while (count < p && (start <= station[i] || end >= station[i])) {
                count++;
                start++;
            }

            if (count >= p) {
                return true;
            }
        }

        return false;
    }
}
