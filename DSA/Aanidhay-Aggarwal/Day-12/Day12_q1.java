import java.util.Scanner;

public class Fibonacci {
    public static int fibonacci(int n) {
        if (n <= 1) {
            return n;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.print("n : ");
        int n = scn.nextInt();
        System.out.println("The " + n + "-th Fibonacci number is: " + fibonacci(n));
    }
}
