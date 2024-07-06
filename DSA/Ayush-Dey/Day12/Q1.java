// Question-1
// Author - Ayush Dey

import java.util.Scanner;

public class Q1 {
    public static int fibonacci(int n) {
        if (n <= 1) {
            return n;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer n: ");
        int n = scanner.nextInt();
        System.out.println("The " + n + "-th Fibonacci number is: " + fibonacci(n));
    }
}