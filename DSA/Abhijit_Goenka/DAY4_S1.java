import java.util.ArrayList;
import java.util.List;
import java.util.*;

public class DAY4_S1 {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String string = sc.nextLine();
        int length = 3;
        int result = PalindromeString(string, length);
        System.out.println(result);
    }

    public static int PalindromeString(String s, int length) 
    {
        String[] substrings = new String[s.length() - length + 1];
        int count = 0;

        for (int i = 0; i <= s.length() - length; i++) 
        {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring) && !contains(substrings, substring)) 
            {
                substrings[count++] = substring;
            }
        }

        return count;
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

    private static boolean contains(String[] array, String value) {
        for (String s : array) {
            if (value.equals(s)) {
                return true;
            }
        }
        return false;
    }
}
