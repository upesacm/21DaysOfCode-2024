//Question-1
//Author - Ayush Dey

import java.util.HashSet; //inorder to remove duplicacy of values
import java.util.Scanner;
import java.util.Set;

public class Q1 {

    // Function to count no. of distinct palindromic substrings of a specific length as per user input
    public static int countPalindromicSubstrings(String s, int length) {
        int n = s.length();
        Set<String> uniqueSubstrings = new HashSet<>();

        for (int i = 0; i <= n - length; i++) {
            String substring = s.substring(i, i + length);
            if (isPalindrome(substring)) {
                uniqueSubstrings.add(substring);
            }
        }

        return uniqueSubstrings.size();
    }

    // Function to check if a given string is a palindrome or not
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
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String string = scanner.nextLine();

        System.out.print("Enter the desired length of substrings: ");
        int length = scanner.nextInt();

        int result = countPalindromicSubstrings(string, length);
        System.out.println(result);
    }
}
