import java.util.Scanner;
public class Day4_ques1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the string:");
        String str=sc.nextLine();
        System.out.println("Enter the length of substrings:");
        int length=sc.nextInt();
        System.out.println("Number of distinct palindromic substrings: "+countDistinctPalindromicSubstrings(str, length));
    }
    public static int countDistinctPalindromicSubstrings(String str, int length) {
        String[] distinctPalindromes = new String[str.length()];
        int count = 0;

        for (int i = 0; i <= str.length() - length; i++) {
            String substring = str.substring(i, i + length);
            if (isPalindrome(substring) && !isDuplicate(distinctPalindromes, substring, count)) {
                distinctPalindromes[count] = substring;
                count++;
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

    private static boolean isDuplicate(String[] array, String s, int count) {
        for (int i = 0; i < count; i++) {
            if (array[i].equals(s)) {
                return true;
            }
        }
        return false;
    }
}
