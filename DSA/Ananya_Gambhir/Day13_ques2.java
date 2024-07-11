import java.util.Scanner;
public class Day13_ques2 {    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();
        System.out.println(isPalindrome(number) ? "YES" : "NO");
        scanner.close();
    }
    
    public static boolean isPalindrome(int number) {
        String numStr = String.valueOf(number);
        return isPalindromeRecursive(numStr, 0, numStr.length() - 1);
    }

    private static boolean isPalindromeRecursive(String str, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (str.charAt(start) != str.charAt(end)) {
            return false;
        }
        return isPalindromeRecursive(str, start + 1, end - 1);
    }
}
