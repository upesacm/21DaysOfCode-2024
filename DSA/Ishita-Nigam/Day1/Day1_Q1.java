import java.util.Scanner;

public class Day1_Q1 {
    public static int countWays(int[] candy, int day, int month) {
        int count = 0;
        for (int i = 0; i <= candy.length - month; i++) {
            int sum = 0;
            for (int j = 0; j < month; j++) {
                sum += candy[i + j];
            }
            if (sum == day) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter array size :");
        int n = in.nextInt();
        int candy[] = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            candy[i] = in.nextInt();
        }
        System.out.println("Enter birth day");
        int day = in.nextInt();
        System.out.println("Enter birth  month");
        int month = in.nextInt();
        System.out.println("Resultant is:" + countWays(candy, day, month));
        in.close();
    }
}