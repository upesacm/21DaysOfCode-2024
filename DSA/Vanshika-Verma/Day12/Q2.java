import java.util.Scanner;

public class day12 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        long n = sc.nextLong();
        int result = sum(n);
        System.out.println("The sum of the digits of " + n + " is: " + result) ;
    }

    public static int sum(long num) {
        if (num < 10) {
            return (int) num;
        } 
        else {
            int sum = 0;
            while (num > 0) 
            {
                sum += num % 10;
                num /= 10;
            }
            return sum(sum) ;
}
}
}
