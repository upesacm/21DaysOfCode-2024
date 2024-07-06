import java.util.Scanner;

public class Day14_Q3 {

    public static int minBulbsToLightHallway(int n, int[] hallway) {
        int[] maxRange = new int[n];

        for (int i = 0; i < n; i++) {
            if (hallway[i] == -1) {
                maxRange[i] = -1;
            } else {
                int left = Math.max(0, i - hallway[i]);
                int right = Math.min(n - 1, i + hallway[i]);
                for (int j = left; j <= right; j++) {
                    maxRange[j] = Math.max(maxRange[j], right);
                }
            }
        }

        int bulbsOn = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (maxRange[i] == -1) {
                return -1;
            }
            farthest = Math.max(farthest, maxRange[i]);
            if (i == currentEnd) {
                bulbsOn++;
                currentEnd = farthest;
                if (currentEnd >= n - 1) {
                    break;
                }
            }
        }

        return currentEnd >= n - 1 ? bulbsOn : -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of partitions: ");
        int n = scanner.nextInt();

        int[] hallway = new int[n];
        System.out.println("Enter the power of bulbs at each partition:");
        for (int i = 0; i < n; i++) {
            hallway[i] = scanner.nextInt();
        }

        int result = minBulbsToLightHallway(n, hallway);
        System.out.println("Minimum number of bulbs to light up the hallway: " + result);

        scanner.close();
    }
}
