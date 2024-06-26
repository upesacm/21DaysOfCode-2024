import java.util.HashSet;

public class PalindromicSubstrings {
    public static int countPalindromicSubstrings(String str, int length) {
        HashSet<String> palindromes = new HashSet<>();

        for (int i = 0; i <= str.length() - length; i++) {
            String substr = str.substring(i, i + length);

            if (isPalindrome(substr)) {
                palindromes.add(substr);
            }
        }

        return palindromes.size();
    }

    public static boolean isPalindrome(String str) {
        int start = 0;
        int end = str.length() - 1;

        while (start < end) {
            if (str.charAt(start) != str.charAt(end)) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }

    public static void main(String[] args) {
        String str = "ababa";
        int length = 3;

        System.out.println("Number of distinct palindromic substrings: " + countPalindromicSubstrings(str, length));
    }
}
