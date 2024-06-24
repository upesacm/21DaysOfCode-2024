import java.util.Scanner;

public class PalindromicSubstrings {
    public static boolean isPalindrome(String s) {
        String reversed = new StringBuilder(s).reverse().toString();
        return s.equals(reversed);
    }

    public static int countPalindromicSubstrings(String s, int length) {
        int count = 0;
        for (int i = 0; i <= s.length() - length; i++) {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring)) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scanner.next();
        System.out.print("Enter the length of the substrings: ");
        int length = scanner.nextInt();
        System.out.println("The number of palindromic substrings is: " + countPalindromicSubstrings(s, length));
    }
}
