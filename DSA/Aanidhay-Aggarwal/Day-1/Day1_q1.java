import java.util.Scanner;

public class CandyBar {
    public static int numWays(int[] candy, int day, int month) {
        int count = 0;
        int windowSum = 0;
        for (int i = 0; i < candy.length; i++) {
            windowSum += candy[i];
            if (i >= month) {
                windowSum -= candy[i - month];
            }
            if (i >= month - 1 && windowSum == day) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the candy array (space-separated): ");
        String[] candyStr = scanner.nextLine().split(" ");
        int[] candy = new int[candyStr.length];
        for (int i = 0; i < candyStr.length; i++) {
            candy[i] = Integer.parseInt(candyStr[i]);
        }

        System.out.print("Enter Raju's birth day: ");
        int day = scanner.nextInt();

        System.out.print("Enter Raju's birth month: ");
        int month = scanner.nextInt();

        int result = numWays(candy, day, month);
        System.out.println("Number of ways to divide the bar: " + result);
    }
}
