import java.util.HashSet;

public class CountPalindromicSubstrings {

    public static int countPalindromicSubstrings(String s, int length) {
        HashSet<String> palindromes = new HashSet<>();

        int n = s.length();
        for (int i = 0; i <= n - length; i++) {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring)) {
                palindromes.add(substring);
            }
        }

        return palindromes.size();
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
        String string = "ababa";
        int length = 3;
        System.out.println(countPalindromicSubstrings(string, length)); // Output: 2
    }
}
