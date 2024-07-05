
public class PalindromeChecker {

    public static boolean isPalindrome(int number) {
        String numStr = Integer.toString(number);
        return isPalindromeRecursive(numStr, 0, numStr.length() - 1);
    }

    private static boolean isPalindromeRecursive(String str, int left, int right) {
        if (left >= right) {
            return true;
        }
   
        if (str.charAt(left) != str.charAt(right)) {
            return false;
        }
        
        return isPalindromeRecursive(str, left + 1, right - 1);
    }

    public static void main(String[] args) {
        int number = 121;
        
        if (isPalindrome(number)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
 
