import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class PalindromicSubstrings {
    public static boolean isPalindrome(String substring) {
        int start = 0;
        int end = substring.length() - 1;
        while (start < end) {
            if (substring.charAt(start)!= substring.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    public static int countPalindromicSubstrings(String s, int length) {
        Set<String> substrings = new HashSet<>();
        for (int i = 0; i <= s.length() - length; i++) {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring)) {
                substrings.add(substring);
            }
        }
        return substrings.size();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String s = scanner.next();
        System.out.print("Enter the length of the substrings: ");
        int length = scanner.nextInt();
        System.out.println("The number of distinct palindromic substrings is: " + countPalindromicSubstrings(s, length));
    }
}
