import java.util.HashSet;
import java.util.Set;

public class Q1 {
    public static boolean isPalindrome(String str) {
        int i = 0, j = str.length() - 1;
        char[] str_array = str.toCharArray();

        while (i < j) {
            if (str_array[i] != str_array[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    public static int solution(String input, int length) {
        Set<String> palindrome_sub_string = new HashSet<>();

        for (int i = 0; i < input.length() - length; i++) {
            String sub_str = input.substring(i, i + length);

            if (isPalindrome(sub_str)) {
                palindrome_sub_string.add(sub_str);
            }
        }

        return palindrome_sub_string.size();
    }


    public static void main(String[] args) {
        String input = "ababa";
        int length = 3;
        int result = solution(input, length);
        System.out.println(result);
    }
}