import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        String str = "ababa";
        int length = 3;
        System.out.println(countPalindromicSubstrings(str, length));
    }
    public static int countPalindromicSubstrings(String str, int length) {
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i <= str.length() - length; i++) {
            String substr = str.substring(i, i + length);
            if (isPalindrome(substr)) {
                set.add(substr);
            }
        }
        return set.size();
    }
    public static boolean isPalindrome(String str) {
        int start = 0;
        int end = str.length() - 1;
        while (start < end) {
            if (str.charAt(start)!= str.charAt(end)) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
}
