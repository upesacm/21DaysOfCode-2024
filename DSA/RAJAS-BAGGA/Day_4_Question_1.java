import java.util.*;

public class Day_4_Question_1 {
    
    public static boolean isPalindrome(String str) {
        int right = str.length()-1;
        int left = 0;
        while (right > left) {
            if (str.charAt(left) != str.charAt(right))
                return false;
            ++left;
            --right;
        }
        return true;
    }
    
    public static int distinctPalindromicSubstrings(String str, int n) {
        int leftptr = 0;
        int rightptr = n-1;
        HashSet<String> seen = new HashSet<String>();
        int strlen = str.length();
        while (rightptr < strlen) {
            String substr = str.substring(leftptr, rightptr+1);
            if (isPalindrome(substr))
                seen.add(substr);
            ++leftptr;
            ++rightptr;
        }
        
        return seen.size();
    }
    public static void main(String[] args) {
        System.out.println(distinctPalindromicSubstrings("ababa", 3));
    }
}
