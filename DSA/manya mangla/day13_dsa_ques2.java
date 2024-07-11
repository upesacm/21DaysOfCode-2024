public class PalindromeChecker {
    
    public static String isPalindrome(int number) {
        String str = Integer.toString(number);
        return isPalindromeHelper(str, 0, str.length() - 1) ? "YES" : "NO";
    }

    private static boolean isPalindromeHelper(String str, int left, int right) {
        // Base case: if left index crosses right, it means we have checked all characters
        if (left >= right) {
            return true;
        }
        // Check characters at left and right positions
        if (str.charAt(left) != str.charAt(right)) {
            return false;
        }
        // Recur for the next pair of characters
        return isPalindromeHelper(str, left + 1, right - 1);
    }

    public static void main(String[] args) {
        int number = 121;
        System.out.println(isPalindrome(number)); // Output: YES

        number = 123;
        System.out.println(isPalindrome(number)); // Output: NO
    }
}
