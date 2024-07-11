import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.print("number : ");
        int number = scn.nextInt();
        System.out.println(isPalindrome(number));
    }

    public static String isPalindrome(int number) {
        int originalNumber = number;
        int reversedNumber = reverseNumber(number);
        return originalNumber == reversedNumber? "YES" : "NO";
    }

    public static int reverseNumber(int number) {
        if (number == 0) {
            return 0;
        }
        return number % 10 + 10 * reverseNumber(number / 10);
    }
}
