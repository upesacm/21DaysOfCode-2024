import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Day4_Q1 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking string input from user
        System.out.println("Enter the string:");
        String inputString = scanner.nextLine();

        // Taking the length of the substrings from the user
        System.out.println("Enter the length of substrings:");
        int substringLength = scanner.nextInt();

        int result = countDistinctPalindromicSubstrings(inputString, substringLength);
        System.out.println("Number of distinct palindromic substrings of length " +  substringLength +  " : " + result);

        scanner.close();
    }

    public static int countDistinctPalindromicSubstrings(String s, int length) {
        if (s == null || s.length() < length) {
            return 0;
        }

        Set<String> palindromicSubstrings = new HashSet<>();

        for (int i = 0; i <= s.length() - length; i++) {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring)) {
                palindromicSubstrings.add(substring);
            }
        }

        return palindromicSubstrings.size();
    }

    private static boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
}
