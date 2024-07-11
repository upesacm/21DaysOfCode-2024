import java.util.Scanner;

public class  day1 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of chocolate squares: ");
        int n = sc.nextInt();
        int[] candy = new int[n];
        System.out.println("Enter the chocolate squares:");
        for (int i = 0; i < n; i++)
        {
            candy[i] = sc.nextInt();
        }
        System.out.print("Enter Raju's birth day: ");
        int day = sc.nextInt();
        System.out.print("Enter Raju's birth month: ");
        int month = sc.nextInt();       
        int count = 0;
       
      //calcuation

        for (int i = 0; i <= n - month; i++)
         {
            int sum = 0;

            for (int j = i; j < i + month; j++) 
            {
                sum += candy[j];
            }

            if (sum == day)
             {
                count++;
            }
        }

        System.out.println("Number of valid ways to divide the bar: " + count);

        
    }
}
