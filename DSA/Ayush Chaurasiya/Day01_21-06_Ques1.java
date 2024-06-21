import java.util.Scanner;

public class Day01_21June {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int size = scanner.nextInt();
        
        int[] candy = new int[size];
        System.out.print("Enter the array: ");
        for(int i=0; i<size; i++){
            candy[i] = scanner.nextInt();
        }

        System.out.print("Enter day: ");
        int day = scanner.nextInt();
        
        System.out.print("Enter month: ");
        int month = scanner.nextInt();    
        
        scanner.close();

        System.out.println("Number of ways: " + findWays(candy, day, month));
    }

    public static int findWays(int[] candy, int day, int month) {
        int ways = 0;
        int n = candy.length;

        for (int i = 0; i <= n - month; i++) {
            int sum = 0;
            for (int j = 0; j < month; j++) {
                sum += candy[i + j];
            }
            if (sum == day) {
                ways++;
            }
        }

        return ways;
    }
}
