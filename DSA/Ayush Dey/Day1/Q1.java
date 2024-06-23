// Question-1
//Author : Ayush Dey
import java.util.Scanner;


public class Q1{

    public static int countValidWays(int[] candy, int day, int month) {
        int n = candy.length;
        int validWays = 0;
        int segmentSum = 0;

        // Initializing the sum for the first segment
        for (int i = 0; i < month; i++) {
            segmentSum += candy[i];
        }

        // Further checking each possible segment
        for (int i = month; i <= n; i++) {
            if (segmentSum == day) {
                validWays++;
            }
            // Finally updating the segment sum for the next iteration
            if (i < n) {
                segmentSum = segmentSum - candy[i - month] + candy[i];
            }
        }

        return validWays;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of chocolate squares: ");
        int n = scanner.nextInt();
        int[] candy = new int[n];
        System.out.println("Enter the chocolate square values:");
        for (int i = 0; i < n; i++) {
            candy[i] = scanner.nextInt();
        }
        System.out.print("Enter Raju's birth day: ");
        int day = scanner.nextInt();

        System.out.print("Enter Raju's birth month: ");
        int month = scanner.nextInt();

        int result = countValidWays(candy, day, month);
        System.out.println(result);

        scanner.close();
    }
}
