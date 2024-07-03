import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        int result = fibo(n);
        System.out.println("The " + n + " Fibonacci number is: " + result);
    }
 public static int fibo(int n) {
        if (n <= 1) 
        {
            return n;
        } 
        else {
            return fibo(n - 1) + fibo(n - 2);
        }
    }
}
