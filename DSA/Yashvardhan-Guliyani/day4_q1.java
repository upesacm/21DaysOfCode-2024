import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class DistinctPalindromeSubstrings {
    public static int countDistinctPalindromes(String s, int length) {
        if (s == null || s.length() < length || length <= 0) {
            return 0;
        }

        Set<String> distinctPalindromes = new HashSet<>();

        for (int i = 0; i <= s.length() - length; i++) {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring)) {
                distinctPalindromes.add(substring);
            }
        }

        return distinctPalindromes.size();
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

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the string: ");
        String s = scanner.nextLine();

        System.out.print("Enter the length of palindromic substrings: ");
        int length = scanner.nextInt();

        int result = countDistinctPalindromes(s, length);
        System.out.println("Number of distinct palindromic substrings: " + result);

        scanner.close();
    }
}
