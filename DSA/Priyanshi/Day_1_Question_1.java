import java.util.*;

public class Day_1_Question_1 
{
    public static int countWays(int[] candy, int day, int month) {
        int count = 0;
        for (int i = 0; i <= candy.length - month; i++) {
            int sum = 0;
            for (int j = i; j < i + month; j++) {
                sum += candy[j];
            }
            if (sum == day) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        int n=0, day=0, month=0;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of array: ");
        n = sc.nextInt();

        int candy[] = new int[n];

        System.out.println("Enter the integers representing the chocolate squares: ");
        for(int i=0;i<n;i++)
        {
            candy[i] = sc.nextInt();
        }

        System.out.println("Enter the day: ");
        day = sc.nextInt();
        System.out.println("Enter the month: ");
        month = sc.nextInt();

        System.out.println("Output: " + countWays(candy, day, month));
    }
}
