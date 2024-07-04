// Question-2
// Author - Ayush Dey

import java.util.Scanner;

public class Q2 {
    public static String isPalindrome(int num, int reverse) {
        if (num == 0) {
            return reverse == num? "YES" : "NO";
        }
        int digit = num % 10;
        reverse = reverse * 10 + digit;
        return isPalindrome(num / 10, reverse);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();
        System.out.println(isPalindrome(number, 0));
    }
}