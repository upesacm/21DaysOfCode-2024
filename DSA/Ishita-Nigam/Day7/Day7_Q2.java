import java.util.Scanner;

public class Day7_Q2 {
    public static int minMaxCost(String str) {
        int n = str.length();
        int[] prefixX = new int[n + 1];
        int[] suffixY = new int[n + 1];

        // Calculate prefixX, which stores the count of 'x' from the start to each
        // position
        for (int i = 0; i < n; i++) {
            prefixX[i + 1] = prefixX[i] + (str.charAt(i) == 'x' ? 1 : 0);
        }

        // Calculate suffixY, which stores the count of 'y' from each position to the
        // end
        for (int i = n - 1; i >= 0; i--) {
            suffixY[i] = suffixY[i + 1] + (str.charAt(i) == 'y' ? 1 : 0);
        }

        int minCost = Integer.MAX_VALUE;

        // Iterate over all possible positions to cut the string
        for (int i = 0; i <= n; i++) {
            int dig0 = prefixX[i]; // 'x' left in the string
            int dig1 = suffixY[i]; // 'y' removed from the string
            minCost = Math.min(minCost, Math.max(dig0, dig1));
        }

        return minCost;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        System.out.println(minMaxCost(str));
        scanner.close();
    }
}