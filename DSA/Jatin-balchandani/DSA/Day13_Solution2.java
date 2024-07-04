public class Day13_Solution2 {

    public static String isPalindrome(int number) {
        String s = Integer.toString(number);
        return checkPalindrome(s, 0, s.length() - 1) ? "YES" : "NO";
    }

    private static boolean checkPalindrome(String s, int left, int right) {
        // Base case: if pointers have crossed, it's a palindrome
        if (left >= right) {
            return true;
        }
        // Check characters at current pointers
        if (s.charAt(left) != s.charAt(right)) {
            return false;
        }
        // Move pointers inward and recurse
        return checkPalindrome(s, left + 1, right - 1);
    }

    public static void main(String[] args) {
        int number = 121;
        System.out.println(isPalindrome(number)); // Output: YES
    }
}
