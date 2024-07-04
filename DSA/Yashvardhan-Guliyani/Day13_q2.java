public class PalindromeCheck {

    public static String isPalindrome(int number) {
        String numStr = Integer.toString(number);
        return isPalindromeHelper(numStr, 0, numStr.length() - 1) ? "YES" : "NO";
    }

    private static boolean isPalindromeHelper(String s, int left, int right) {
        if (left >= right) {
            return true; 
        }
        if (s.charAt(left) != s.charAt(right)) {
            return false; 
        }
        return isPalindromeHelper(s, left + 1, right - 1); 
    }

    public static void main(String[] args) {
        int number = 121;
        System.out.println(isPalindrome(number)); // Output: YES

        number = 123;
        System.out.println(isPalindrome(number)); // Output: NO
    }
}
