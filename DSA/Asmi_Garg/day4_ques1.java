import java.util.Scanner;

public class PalindromicSubstrings {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter the string: ");
            String inputString = scanner.nextLine();

            System.out.print("Enter the length of the substrings:");
            int length = scanner.nextInt();

            int result = countPalindromicSubstrings(inputString, length);

            System.out.println("Number of distinct palindromic substrings of length " + length + ": " + result);
        }
    }

    public static int countPalindromicSubstrings(String s, int length) {
        if (s == null || s.length() < length || length <= 0) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i <= s.length() - length; i++) {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring)) {
                count++;
                i += length - 1;
            }
        }

        return count;
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
