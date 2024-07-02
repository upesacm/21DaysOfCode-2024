// Question-2
// Author - Ayush Dey

import java.util.Scanner;

public class Q2 {
    public static int sumDigits(int n) {
        if (n < 10) {
            return n;
        }
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sumDigits(sum);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a large integer: ");
        int number = scanner.nextInt();
        System.out.println("The single digit result is: " + sumDigits(number));
    }
}