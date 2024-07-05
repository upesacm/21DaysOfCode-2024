import java.util.Scanner;

public class Day13_que2 {

    public static String isPalindrome(int number) {
        String numString = String.valueOf(number);
        if (checkPalindrome(numString, 0, numString.length() - 1)) {
            return "YES";
        } else {
            return "NO";
        }
    }

    private static boolean checkPalindrome(String s, int left, int right) {
        if (left >= right) {
            return true; 
        }
        if (s.charAt(left) != s.charAt(right)) {
            return false; 
        }
        return checkPalindrome(s, left + 1, right - 1);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number to check if it's a palindrome:");
        int number = scanner.nextInt();
        scanner.close();
        System.out.println("Is " + number + " a palindrome? " + isPalindrome(number));
    }
}
